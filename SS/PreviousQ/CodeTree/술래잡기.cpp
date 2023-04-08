#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;  // 격자 크기
int M;  // 도망자 수
int H;  // 나무 수
int K;  // 라운드 수
int turn; // 현재 턴 횟수
vector<pair<int, int>> Tree;  // 나무
pair<int, int> Tagger; // 술래
int score = 0;  // 술래가 얻은 점수
// 술래 이동
int dx[4] = { -1,0,1,0 }; // 상 우 하 좌
int dy[4] = { 0,1,0,-1 };
int see = 0;  // 술래가 보고 있는 방향(=이동방향)
// 도망자 이동
pair<int, int> dxdy[3][2] = { {{0,0}, {0,0}},
                            {{0,1}, {0,-1}}, // 우 좌
                            {{1,0}, {-1,0}} }; // 하 상
struct Runner {  // 도망자
    int X, Y; // 위치
    int D;  // 이동 방법 1:좌우 2:상하
    int _D; // 0:좌/상 1:우/하
    bool live;  // 살았나 죽었나
}R[10000];

pair<int, int> dist[20000]; // 달팽이 번호
int taggerSee[20000];   // 술래 시야
// 달팽이로 위치 번호 저장
void snail() {
    int startx = Tagger.first;
    int starty = Tagger.second;
    taggerSee[0] = 0;
    int step = 1;
    int num = 1;
    while (num < pow(N, 2)) {
        if (step % 2 == 1) {    // 홀수스텝
            for (int i = 1; i <= step; i++) {   // 상
                startx += dx[0];
                starty += dy[0];
                dist[num] = make_pair(startx, starty);
                taggerSee[num] = 0;
                num++;
            }
            taggerSee[num - 1] = 1;
            for (int i = 1; i <= step; i++) {   // 우
                startx += dx[1];
                starty += dy[1];
                dist[num] = make_pair(startx, starty);
                taggerSee[num] = 1;
                num++;
            }
            taggerSee[num - 1] = 2;
        }
        else {  // 짝수스텝
            for (int i = 1; i <= step; i++) {   // 하
                startx += dx[2];
                starty += dy[2];
                dist[num] = make_pair(startx, starty);
                taggerSee[num] = 2;
                num++;
            }
            taggerSee[num - 1] = 3;
            for (int i = 1; i <= step; i++) {   // 좌
                startx += dx[3];
                starty += dy[3];
                dist[num] = make_pair(startx, starty);
                taggerSee[num] = 3;
                num++;
            }
            taggerSee[num - 1] = 0;
        }
        step++;
    }
    num = pow(N, 2) - 1;
    taggerSee[num++] = 2;    // 아래
    taggerSee[num++] = 2;
    // 경계에서
    step -= 2;
    startx = 1; starty = 1;
    
    for (int i = 1; i <= step; i++) {
        startx += dx[2];
        starty += dy[2];
        dist[num] = make_pair(startx, starty);
        taggerSee[num] = 2;
        num++;
    }
    taggerSee[num - 1] = 1;
    while (num < 2 * pow(N, 2) && step > 0) {
        if(step % 2 == 0) {  // 짝수스텝
            for (int i = 1; i <= step; i++) {   // 우
                startx += dx[1];
                starty += dy[1];
                dist[num] = make_pair(startx, starty);
                taggerSee[num] = 1;
                num++;
            }
            taggerSee[num - 1] = 0;
            for (int i = 1; i <= step; i++) {   // 상
                startx += dx[0];
                starty += dy[0];
                dist[num] = make_pair(startx, starty);
                taggerSee[num] = 0;
                num++;
            }
            taggerSee[num - 1] = 3;
        }
        else {  // 짝수스텝
            for (int i = 1; i <= step; i++) {   // 좌
                startx += dx[3];
                starty += dy[3];
                dist[num] = make_pair(startx, starty);
                taggerSee[num] = 3;
                num++;
            }
            taggerSee[num - 1] = 2;
            for (int i = 1; i <= step; i++) {   // 하
                startx += dx[2];
                starty += dy[2];
                dist[num] = make_pair(startx, starty);
                taggerSee[num] = 2;
                num++;
            }
            taggerSee[num - 1] = 1;
        }
        step--;
    }
    num = 2 * pow(N, 2) - 1;
    taggerSee[num] = 0; // == taggerSee[0]


    //// 출력
    //for (int i = 0; i < 2 * pow(N, 2); i++)
    //    cout << taggerSee[i] << " ";
    //cout << "\n";
}

// 입력
void input() {
    cin >> N >> M >> H >> K;
    Tagger = { (N + 1) / 2, (N + 1) / 2 };  // 술래 위치 정중앙
    for (int i = 0; i < M; i++) {
        cin >> R[i].X >> R[i].Y >> R[i].D;
        R[i]._D = 0;  // 시작 방향 설정
        R[i].live = true; // 살았음
    }
    for (int i = 0; i < H; i++) {
        int a, b;
        cin >> a >> b;
        Tree.push_back({ a, b });
    }
    snail();
}

// 범위 체크
bool overRange(int a, int b) {
    if (a <= 0 || a > N || b <= 0 || b > N) return true;
    return false;
}

// 1. 도망자 움직임
void moveRunner(int i) {
    // 술래랑 거리 차이
    int runnerX = R[i].X;
    int runnerY = R[i].Y;
    int dist = abs(Tagger.first - runnerX) + abs(Tagger.second - runnerY);
    if (dist > 3) return;  // 3 초과이면 안움직임
    // 움직임
    int nx = runnerX + dxdy[R[i].D][R[i]._D].first; // 움직일 위치
    int ny = runnerY + dxdy[R[i].D][R[i]._D].second;
    if (overRange(nx, ny)) {
        R[i]._D = (R[i]._D + 1) % 2;  // 방향 반대로 돌림
        nx = runnerX + dxdy[R[i].D][R[i]._D].first;
        ny = runnerY + dxdy[R[i].D][R[i]._D].second;
    }
    if (nx == Tagger.first && ny == Tagger.second) // 술래 있으면 안움직임
        return;
    // 움직임!
    R[i].X = nx;
    R[i].Y = ny;
}

int tmpTurn = 1;    // 달팽이 돌릴 때 사용할 턴 횟수
// 2-1. 달팽이로 술래 위치, 방향 바뀜
void moveTagger() {
    int baf = pow(N, 2);
    if (tmpTurn == baf || tmpTurn == 2 * baf - 1) tmpTurn++;
    tmpTurn %= (2 * baf);
    Tagger.first = dist[tmpTurn].first;
    Tagger.second = dist[tmpTurn].second;
    see = taggerSee[tmpTurn];

    tmpTurn++;
}

// 2-2. 도망자 잡기
void catchRunner() {
    for (int i = 0; i < 3; i++) {
        int seex = Tagger.first + (dx[see] * i);
        int seey = Tagger.second + (dy[see] * i);
        if (overRange(seex, seey)) break;
        if (find(Tree.begin(), Tree.end(), make_pair(seex, seey)) != Tree.end())
            continue;  // 나무가 있으면 패쓰
        for (int k = 0; k < M; k++) {
            if (R[k].X == seex && R[k].Y == seey) {
                if (!R[k].live) continue;
                R[k].live = false;  // 죽었음
                score += turn;
            }
        }
    }
}


// 도망자 위치 프린트
void runnerPrint() {
    cout << "///////////// 도망자\n";
    for (int i = 0; i < M; i++) {
        if (!R[i].live) continue;
        cout << R[i].X << ", " << R[i].Y << "\n";
    }
    cout << "////////////////\n";
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    input();

    //// 테스트 ************************
    //turn = 1;
    //for (int i = 0; i < M; i++) {
    //    moveRunner(i);
    //}
    //runnerPrint();
    //catchRunner();
    //cout << "score: " << score << "\n";
    //turn = 2;
    //for (int i = 0; i < M; i++) {
    //    moveRunner(i);
    //}
    //runnerPrint();
    //// *****************************

     for(turn=1; turn<=K; turn++){
       // 1. 도망자 움직임
       for(int i=0; i<M; i++){
           if (!R[i].live) continue;  // 죽었으면 패쓰
           moveRunner(i);
       }

       // 2. 술래 움직임
       // 2-1. 달팽이로 술래 위치, 방향 바뀜
       moveTagger();

       // 2-2. 도망자 잡기
       catchRunner();
     }

     cout << score;
}
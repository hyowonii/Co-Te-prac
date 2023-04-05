#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define R first
#define C second

int n;  // 격자 변길이
int m;  // 사람 수
int board[20][20];  // 격자 (0:빈칸, 1:베이스캠프, -1:못가는칸)
pair<int, int> shop[35]; // 편의점
pair<int, int> human[35];    // 사람 위치
int dr[4] = { -1,0,0,1 };
int dc[4] = { 0,-1,1,0 };
int T = 0; // 시간
int dist[20][20];   // bfs 값 저장 배열
int minRoadCnt = 260;
pair<int, int> mv;

// 입력
void init() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    for (int k = 1; k <= m; k++) {
        int r, c;
        cin >> r >> c;
        shop[k] = { r,c };  // 편의점 위치
    }
}

// BFS : 기준 지점으로부터 모든 격자까지의 최단 거리 구함
void BFS(int sr, int sc) {  // 시작점
    // 거리 배열 초기화
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = 10000;

    queue<pair<int,int>> Q;
    Q.push(make_pair(sr,sc));
    dist[sr][sc] = 0;

    while (!Q.empty()) {
        auto cur = Q.front();   Q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = cur.first + dr[k];
            int nc = cur.second + dc[k];
            if (nr <= 0 || nr > n || nc <= 0 || nc > n) continue;
            if (dist[nr][nc] != 10000) continue;
            if (board[nr][nc] == -1) continue;
            dist[nr][nc] = dist[cur.first][cur.second] + 1;
            Q.push(make_pair(nr, nc));
        }
    }
}

// 편의점에 도착했는지
bool isArrived(int idx) {
    return human[idx].first == shop[idx].first && human[idx].second == shop[idx].second;
}

// 1. 최단거리로 한 칸 이동
void moveHuman(int idx) {
    if (isArrived(idx)) return;    // 이미 도착한 사람 무시

    // **편의점을 기준**으로 모든 격자의 최단 거리 계산하기
    BFS(shop[idx].first, shop[idx].second);

    // 자신과 인접한 네 곳을 보면서 어디로 갈 지 정하기
    int minDist = 10000, minDir = -1;
    for (int k = 0; k < 4; k++) {
        int nr = human[idx].first + dr[k];
        int nc = human[idx].second + dc[k];
        if (nr <= 0 || nr > n || nc <= 0 || nc > n) continue;
        //if (board[nr][nc] == -1) continue;
        if (dist[nr][nc] < minDist) {
            minDist = dist[nr][nc];
            minDir = k;
        }
    }

    // 결정한 방향으로 한 칸 이동
    human[idx].first += dr[minDir];
    human[idx].second += dc[minDir];
}

// 2. 도착 시 멈춤
void stop(int idx) {
    if (isArrived(idx)) {
        board[human[idx].first][human[idx].second] = -1;
    }
}

// 3. t분에 t번사람 베이스캠프 들어감
void baseCamp(int t) {
    // 먼저, 목표 위치에서 각 베이스 캠프 까지의 최단 거리
    BFS(shop[t].first, shop[t].second);

    // 가장 가까운 베이스캠프 찾기
    int minDist = 10000, minR = 0, minC = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] != 1) continue; // 베이스캠프가 아닌 곳 무시
            if (dist[i][j] < minDist) {
                minDist = dist[i][j];
                minR = i;
                minC = j;
            }
        }
    }

    human[t].first = minR;
    human[t].second = minC;
    board[minR][minC] = -1;
}

// 모두 편의점에 도착하면 종료
bool isfinished() {
    for (int i = 1; i <= m; i++) {
        if (!isArrived(i)) return false;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 입력
    init();

    while (!isfinished()) {    // 모두 편의점에 도착하면 종료

        T++;

        // 1. 최단거리로 한 칸 이동 
        for (int i = 1; i < T && i <= m; i++) {
            moveHuman(i);
        }
        
        // 2. 도착 시 멈춤
        for (int i = 1; i < T && i <= m; i++) {
            stop(i);
        }

        // 3. t분에 t번사람 베이스캠프 들어감
        if (T <= m) {
            baseCamp(T);
        }
    }
    
    cout << T;

    return 0;
}
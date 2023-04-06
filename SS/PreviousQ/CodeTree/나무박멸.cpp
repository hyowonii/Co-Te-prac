#include <iostream>
#include <queue>
using namespace std;

int n;  // 격자 크기
int m;  // 진행 년 수
int kP;  // 제초제 확산 범위
int C;  // 제초제 남는 년 수
int board[21][21][2]; // [0]: 나무,벽  [1]: 제초제
int dr[4] = { -1,0,0,1 }; // 상 좌 우 하
int dc[4] = { 0,-1,1,0 };
int total = 0;  // 총 박멸한 나무 그루 수

// 입력
void input() {
    cin >> n >> m >> kP >> C;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j][0];
        }
    }
}

// 1. 나무 성장
void grow() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j][0] == 0 || board[i][j][0] == -1) continue; // 나무x
            int cnt = 0;  // 사방의 나무 갯수
            for (int k = 0; k < 4; k++) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (nr >= 1 && nr <= n && nc >= 1 && nc <= n && board[nr][nc][0] != 0 && board[nr][nc][0] != -1)
                    cnt++;
            }
            board[i][j][0] += cnt;
        }
    }
}

// 2. 나무 번식
void propagation() {
    int tmp[21][21] = { 0 };  // 번식 나무 수 저장할 임시 배열
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j][0] == 0 || board[i][j][0] == -1) continue; // 나무x
            if (board[i][j][1] > 0) continue;  // 제초제 있는 칸 나무x
            queue<pair<int, int>> locs; // 번식할 위치
            for (int k = 0; k < 4; k++) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (nr <= 0 || nr > n || nc <= 0 || nc > n) continue;  // 범위 넘어감
                if (board[nr][nc][0] == 0 && board[nr][nc][1] == 0)  // 제초제 없는 빈칸
                    locs.push(make_pair(nr, nc));
            }
            if (locs.size() == 0) continue; // 번식할 공간 없으면 패쓰 *** 놓친 부분
            int tree = board[i][j][0] / locs.size();
            while (!locs.empty()) {
                auto loc = locs.front();  locs.pop();
                tmp[loc.first][loc.second] += tree;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            board[i][j][0] += tmp[i][j];
        }
    }
}

// 3(1) 가장 많이 박멸되는 칸 구하기
pair<int, int> mostDie() {
    int da[4] = { -1,-1,1,1 };
    int db[4] = { -1,1,-1,1 };
    int maxCnt = 0;
    pair<int, int> result;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j][0] > 0) { // 나무
                int tmpCnt = board[i][j][0];
                for (int q = 0; q < 4; q++) {  // 한방향으로 dfs처럼
                    for (int p = 1; p <= kP; p++) { // 확산 범위만큼 한칸씩 늘려감
                        int nr = i + da[q] * p;
                        int nc = j + db[q] * p;
                        if (nr <= 0 || nr > n || nc <= 0 || nc > n) break;
                        if (board[nr][nc][0] == -1) break; // 벽을 만나면 확산 멈춤
                        if (board[nr][nc][0] == 0) {  // 나무가 아예 없으면
                            break;  // 더이상 확산하지 않음
                        }
                        tmpCnt += board[nr][nc][0];
                    }
                }
                if (tmpCnt > maxCnt) {
                    maxCnt = tmpCnt;
                    result = make_pair(i, j);  // 가장 많이 박멸되는 나무 위치 리턴
                }
            }
        }
    }
    total += maxCnt;
    return result;
}

// 3. 제초제 뿌리기
void putPoison() {
    // 3(1) 가장 많이 박멸되는 칸 구하기
    pair<int, int> target = mostDie();
    int r = target.first;
    int c = target.second;
    board[r][c][1] = C; // 제초제 뿌린 나무 칸에 제초제 남음
    board[r][c][0] = 0; // 제초제 뿌린 나무 칸에 나무 없어짐  
    int da[4] = { -1,-1,1,1 };
    int db[4] = { -1,1,-1,1 };
    for (int q = 0; q < 4; q++) {  // 한방향으로 dfs처럼
        for (int p = 1; p <= kP; p++) { // 확산 범위만큼 한칸씩 늘려감
            int nr = r + da[q] * p;
            int nc = c + db[q] * p;
            if (nr <= 0 || nr > n || nc <= 0 || nc > n) break;
            if (board[nr][nc][0] == -1) break; // 벽을 만나면 확산 멈춤
            if (board[nr][nc][0] == 0) {  // 나무가 아예 없으면
                board[nr][nc][1] = C;
                break;  // 더이상 확산하지 않음
            }
            // 나무 있으면
            board[nr][nc][1] = C; // 제초제 남음
            board[nr][nc][0] = 0; // 나무 사라짐
        }
    }

}

// 이전에 뿌렸던 제초제 -1
void reducePoison() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j][1] > 0) board[i][j][1]--;
        }
    }
}

// 임시) 프린트
void print(int idx) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << board[i][j][idx] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 입력
    input();

    //// 테스트
    //grow();
    //propagation();
    //print(0);
    //reducePoison();
    //print(1);
    //putPoison();
    //print(1);
    //cout << "///////////\n";
    //grow();
    //print(0);
    //propagation();
    //print(0);
    //reducePoison();
    //print(1);
    //putPoison();
    //print(1);
    ////

    while (m--) {
        // 1. 나무 성장
        grow();

        // 2. 나무 번식
        propagation();

        // 이전에 뿌렸던 제초제 -1
        reducePoison();

        // 3. 제초제 뿌리기
        putPoison();

    }

    cout << total;

}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;  // 보드 N x N
int result = 0;

// int dx[4] = {-1,0,1,0}; // 위, 왼, 아래, 오
// int dy[4] = {0,-1,0,1};


// 가장 큰 블럭 찾기
int maxB(vector<vector<int>> board){
  int mx = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      mx = max(mx, board[i][j]);
    }
  }
  return mx;
}

// 오른쪽으로 
vector<vector<int>> right(vector<vector<int>> board){

  // 두 블럭이 합쳐진건지 체크
  bool check[25][25];
  fill(&check[0][0], &check[N][N], false);

  for(int i=0; i<N; i++){
    for(int j=N-2; j>=0; j--){
      if(board[i][j] == 0) continue;
      for(int k=j+1; k<N; k++){
        if(board[i][k] == board[i][k-1] && !check[i][k]){
          board[i][k] *= 2;
          board[i][k-1] = 0;
          check[i][k] = true;
          break;
        }
        else if(board[i][k] == 0){
          board[i][k] = board[i][k-1];
          board[i][k-1] = 0;
        }
        else break;
      }
    }
  }
  return board;
}

// 왼쪽으로 
vector<vector<int>> left(vector<vector<int>> board){
  
  // 두 블럭이 합쳐진건지 체크
  bool check[25][25];
  fill(&check[0][0], &check[N][N], false);

  for(int i=0; i<N; i++){
    for(int j=1; j<N; j++){
      if(board[i][j] == 0) continue;
      for(int k=j-1; k>=0; k--){
        if(board[i][k] == board[i][k+1] && !check[i][k]){
          board[i][k] *= 2;
          board[i][k+1] = 0;
          check[i][k] = true;
          break;
        }
        else if(board[i][k] == 0){
          board[i][k] = board[i][k+1];
          board[i][k+1] = 0;
        }
        else break;
      }
    }
  }
  return board;
}

// 위쪽으로
vector<vector<int>> up(vector<vector<int>> board){
  
  // 두 블럭이 합쳐진건지 체크
  bool check[25][25];
  fill(&check[0][0], &check[N][N], false);

  for(int j=0; j<N; j++){
    for(int i=1; i<N; i++){
      if(board[i][j] == 0) continue;
      for(int k=i-1; k>=0; k--){
        if(board[k][j] == board[k+1][j] && !check[k][j]){
          board[k][j] *= 2;
          board[k+1][j] = 0;
          check[k][j] = true;
          break;
        }
        else if(board[k][j] == 0){
          board[k][j] = board[k+1][j];
          board[k+1][j] = 0;
        }
        else break;
      }
    }
  }
  return board;
}

// 아래쪽으로
vector<vector<int>> down(vector<vector<int>> board){
  
  // 두 블럭이 합쳐진건지 체크
  bool check[25][25];
  fill(&check[0][0], &check[N][N], false);

  for(int j=0; j<N; j++){
    for(int i=N-2; i>=0; i--){
      if(board[i][j] == 0) continue;
      for(int k=i+1; k<N; k++){
        if(board[k][j] == board[k-1][j] && !check[k][j]){
          board[k][j] *= 2;
          board[k-1][j] = 0;
          check[k][j] = true;
          break;
        }
        else if(board[k][j] == 0){
          board[k][j] = board[k-1][j];
          board[k-1][j] = 0;
        }
        else break;
      }
    }
  }
  return board;
}

void recurse(int cnt, vector<vector<int>> board){
  result = max(result, maxB(board)); // 최댓값 갱신  

  if(cnt == 5) return;

  // for(int i=0; i<4; i++){
  //   int xdir = dx[i];
  //   int ydir = dy[i];
  // }

  recurse(cnt+1, right(board));
  recurse(cnt+1, left(board));
  recurse(cnt+1, up(board));
  recurse(cnt+1, down(board));
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  vector<vector<int>> board(N, vector<int>(N));  // 보드판

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> board[i][j];
    }
  }

  recurse(0, board);

  cout << result;

  ///////////////////////////

  // cout << "right\n";
  // vector<vector<int>> newboard1 = right(board);
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     cout << newboard1[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  // cout << "left\n";
  // vector<vector<int>> newboard2 = left(board);
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     cout << newboard2[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  // cout << "up\n";
  // vector<vector<int>> newboard3 = up(board);
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     cout << newboard3[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  // cout << "down\n";
  // vector<vector<int>> newboard4 = down(board);
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     cout << newboard4[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  
}
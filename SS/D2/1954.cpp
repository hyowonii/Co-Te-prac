#include<iostream>

using namespace std;

int N;
int arr[11][11] = {0};
int dr[4] = {0,-1,0,1}; // 오, 위, 왼, 아래
int dc[4] = {1,0,-1,0};

void input(){
  cin >> N;
  fill(&arr[0][0], &arr[11][11], 0);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{

		// 입력
    input();

    int n = N;
    int cnt = 1;  // 저장할 번호
    int curr = 0, curc = -1; // 저장 인덱스
    for(int i=0; i<n; i++){
      arr[curr][++curc] = cnt++;
    }
    n -= 1;
    
    bool tmp = true;
    while(n > 0){
      if(tmp){  // 아래, 왼
        for(int i=1; i<=n; i++){  // 아래
          curr += dr[3];
          curc += dc[3];
          arr[curr][curc] = cnt++;
        }
        for(int i=1; i<=n; i++){  // 왼
          curr += dr[2];
          curc += dc[2];
          arr[curr][curc] = cnt++;
        }
      }
      else{ // 위, 오른
        for(int i=1; i<=n; i++){  // 위
          curr += dr[1];
          curc += dc[1];
          arr[curr][curc] = cnt++;
        }
        for(int i=1; i<=n; i++){  // 오른
          curr += dr[0];
          curc += dc[0];
          arr[curr][curc] = cnt++;
        }
      }
      tmp = !tmp;
      n--;
    }

    cout << "#" << test_case << "\n";
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        cout << arr[i][j] << " ";
      }
      cout << "\n";
    }

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
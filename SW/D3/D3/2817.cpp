#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> nums;
int result = 0;

void func(int pos, int sum) {
  if(sum == k) {
    result++;
    return;
  }

  if(pos >= n) return;

  func(pos+1, sum+nums[pos]);
  func(pos+1, sum);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{

		// int n, k; 
    cin >> n >> k;
    // vector<int> nums;
    nums.clear(); // 벡터 초기화
    for(int i=0; i<n; i++) {
      int num;
      cin >> num;
      nums.push_back(num);
    }
    sort(nums.begin(), nums.end()); // 정렬
    result = 0; // 결과값 초기화

    func(0, 0);

    cout << "#" << test_case << " " << result << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
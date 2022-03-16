#include <iostream>
#include <vector>

using namespace std;


typedef pair<int, int> ci;


int tryAll(int n, vector<ci> contest) {

	long long sum = 0; //상금 합

	//처음으로 상금 제한에 걸려 참가가 불가능해진 대회 찾기 - idx번째
	for (int i = 0; i < n - 2; i++) {

		if (sum + contest[i].second > contest[i + 1].first) { //이번 대회상금을 얻으면 다음대회를 못나가게 된다면
			return i + 1; //못나가는 대회 인덱스 반환
		}

		sum += contest[i].second;

	}

	return -1; //-1 일경우 성공 한것.

}

// idx번째 대회만 빼고 참가해보기.
bool exceptIdx(int n, vector<ci> contest, int idx) {

	long long sum = 0;
	for (int i = 0; i < n; i++) {

		if (i == idx)
			continue;

		if (sum > contest[i].first) { //지금 까지 얻은 상금이 이번대회의 상금제한조건보다 크다면
			return false;

		}
		sum += contest[i].second;

	}

	return true;

}

// idx번째 대회 이전에 열린 대회 중 받는 상금이 제일 큰 대회를 골라, 그 대회에 불참해보기
bool exceptLargestBeforeIdx(int n, vector<ci> contest, int idx) {

	int largest_reward = -1;
	int largest_idx;// 가장 상금이 큰 대회의 인덱스

	for (int i = 0; i < idx; i++) {

		if (largest_reward < contest[i].second) {
			largest_idx = i;
			largest_reward = contest[i].second;
		}

	}

	return  exceptIdx(n, contest, largest_idx);
}

int main() {


	int n;
	cin >> n;

	vector<ci> contest(n, { 0,0 }); // first : 참가조건 , second : 상금

	for (int i = 0; i < n; i++) {
		cin >> contest[i].first >> contest[i].second;
	}


	int result = tryAll(n, contest);


	if (result == -1) { //모든 대회 참가 성공시
		cout << "Kkeo-eok";
	}
	else {

		if (exceptIdx(n, contest, result)) {
			cout << "Kkeo-eok";
		}
		else {

			if (exceptLargestBeforeIdx(n, contest, result)) {
				cout << "Kkeo-eok";
			}
			else
				cout << "Zzz";

		}

	}

}
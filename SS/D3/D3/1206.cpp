/*
	SW Expert Academy [View]
	https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&problemLevel=4&contestProbId=AV134DPqAA8CFAYh&categoryId=AV134DPqAA8CFAYh&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=1
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 1; t <= 10; t++) {
		int len;
		int building[1000];
		int answer = 0;

		// ют╥б
		cin >> len;
		for (int i = 0; i < len; i++) cin >> building[i];
		//

		for (int i = 2; i <= len - 2; i++) {
			int del = 1000;
			for (int j = i - 2; j <= i + 2; j++) {
				if (j == i) continue;
				del = min(del, building[i] - building[j]);
			}
			
			if (del >= 0) answer += del;
		}

		cout << "#" << t << " "<< answer << "\n";
	}
}
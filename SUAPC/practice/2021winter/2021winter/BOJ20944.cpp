#include <iostream>
#include <ctime>
using namespace std;
#define MAX 1000000

int N;
string s = "";

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	srand((unsigned)time(NULL));
	char c = 'a' + rand() % 26;
	if (N % 2 == 0) {
		while (N--) {
			cout << c;
		}
	}
	else {
		char c2 = 'a' + rand() % 26;
		for (int i = 0; i < N / 2; i++) cout << c;
		cout << c2;
		for (int i = 0; i < N / 2; i++) cout << c;
	}
	return 0;
	
}
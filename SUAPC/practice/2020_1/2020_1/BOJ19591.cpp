#include <iostream>
using namespace std;
#include <deque>
#include <string>
#include <cctype>
#include <typeinfo>

string s;
deque<long long> dq_num;
deque<char> dq_op;

long long calcul(long long n1, long long n2, char op) {
	long long result = 0;
	switch (op)
	{
	case '+': result = n1 + n2; break;
	case '-': result = n1 - n2; break;
	case '*': result = n1 * n2; break;
	case '/': result = n1 / n2; break;
	}
	return result;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	int i = 0;
	int k = 0;
	int minus = 1;
	if (!isdigit(s[0])) {
		minus = -1;
		i = 1;
	}
	for (i; i < s.length(); i++) {

		if (isdigit(s[i])) {

			k = 10 * k + (s[i] - '0');
		}
		else {
			k *= minus;
			minus = 1;
			dq_num.push_back(k);
			k = 0;

			dq_op.push_back(s[i]);
		}
	}
	dq_num.push_back(minus * k);

	// ¿¬»ê
	while (!dq_op.empty()) {
		char op1 = dq_op.front(); 
		char op2 = dq_op.back(); 

		long long n1 = dq_num.front(); dq_num.pop_front();
		long long n2 = dq_num.front();
		long long result1 = calcul(n1, n2, op1);

		if (dq_op.size() == 1) {
			dq_num.pop_front();
			dq_num.push_front(result1);
			dq_op.pop_front();
			continue;
		}

		long long n4 = dq_num.back(); dq_num.pop_back();
		long long n3 = dq_num.back();
		long long result2 = calcul(n3, n4, op2);

		if (op1 == '*' || op1 == '/') {

			if (op2 == '*' || op2 == '/') {
				if (result1 < result2) {
					dq_num.pop_back();
					dq_num.push_back(result2);
					dq_op.pop_back();
					dq_num.push_front(n1);
					continue;
				}
			}

			dq_num.pop_front();
			dq_num.push_front(result1);
			dq_op.pop_front();
			dq_num.push_back(n4);
			continue;
		}

		if (op2 == '*' || op2 == '/') {
			dq_num.pop_back();
			dq_num.push_back(result2);
			dq_op.pop_back();
			dq_num.push_front(n1);
			continue;
		}

		if (result1 >= result2) {
			dq_num.pop_front();
			dq_num.push_front(result1);
			dq_op.pop_front();
			dq_num.push_back(n4);
		}
		else {
			dq_num.pop_back();
			dq_num.push_back(result2);
			dq_op.pop_back();
			dq_num.push_front(n1);
		}
	}

	cout << dq_num.front();
	

}


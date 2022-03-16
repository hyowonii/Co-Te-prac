#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c; // 입력
    cin >> a >> b >> c;
    int d, e, f; // 크기 순으로 출력할 세 수
    d = min({ a,b,c });
    f = max({ a,b,c });
    e = a + b + c - d - f;
    cout << d << ' ' << e << ' ' << f;
}
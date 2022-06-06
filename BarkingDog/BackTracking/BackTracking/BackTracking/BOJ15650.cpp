#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int N, M;
vector<int> a;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // M�� ������ŭ 0�� �־���
    for (int i = 0; i < N; ++i)  a.push_back(i < M ? 0 : 1);

    do {

        for (int i = 0; i < N; ++i)
            if (a[i] == 0) cout << i + 1 << ' ';
        cout << '\n';

    } while (next_permutation(a.begin(), a.end()));
}
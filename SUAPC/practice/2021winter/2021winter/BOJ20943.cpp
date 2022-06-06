#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INF 987654321

using namespace std;
map< double, int> slope; //기울기, 해당 기울기를 가진 직선.

int nC2(int n) {
    return n * (n - 1) / 2;
}


int main() {
    


    int n;
    cin >> n;
    long a, b, c;

 
    // 같은 기울기를 가진 직선들 수 세기
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        if (b == 0) { //세로 직선 : 기울기 무한대
            slope[INF] ++;
        }
        else {
            double t = (double)a / b;
            slope[t] ++;
        }

    }

    int total = nC2(n);


    // 맵을 순회하면서 같은 기울기를 지닌 직선중 2개를 선택하는 경우의 수를 빼준다.
    for (auto iter : slope) {
        int k = iter.second;

        if (k >= 2) {
            total -= nC2(k);
        }
    }
  
    cout << total;
}
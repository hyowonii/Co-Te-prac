#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INF 987654321

using namespace std;
map< double, int> slope; //����, �ش� ���⸦ ���� ����.

int nC2(int n) {
    return n * (n - 1) / 2;
}


int main() {
    


    int n;
    cin >> n;
    long a, b, c;

 
    // ���� ���⸦ ���� ������ �� ����
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        if (b == 0) { //���� ���� : ���� ���Ѵ�
            slope[INF] ++;
        }
        else {
            double t = (double)a / b;
            slope[t] ++;
        }

    }

    int total = nC2(n);


    // ���� ��ȸ�ϸ鼭 ���� ���⸦ ���� ������ 2���� �����ϴ� ����� ���� ���ش�.
    for (auto iter : slope) {
        int k = iter.second;

        if (k >= 2) {
            total -= nC2(k);
        }
    }
  
    cout << total;
}
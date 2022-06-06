#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long total1 = 0;
long long total2 = 0;
long long total = 0;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int size = queue1.size();

    // 만들어야 하는 원소 합
    for (int i = 0; i < size; i++) {
        total1 += queue1[i];
    }
    for (int i = 0; i < size; i++) {
        total2 += queue2[i];
    }
    total = total1 + total2;
    if (total % 2 != 0) return -1;
    total /= 2;

    int mx1 = *max_element(queue1.begin(), queue1.end());
    int mx2 = *max_element(queue2.begin(), queue2.end());
    if (mx1 > total || mx2 > total) return -1;

    vector<int> cpy;
    cpy.resize(size);
    copy(queue2.begin(), queue2.end(), cpy.begin());

    while (true) {
        if (total1 == total2) break;
        if (queue1.size() == 0 || queue2.size() == 0) return -1;
        if (equal(cpy.begin(), cpy.end(), queue1.begin())) return -1;

        if (total1 < total2) {
            while (total1 < total2) {
                int p = queue2[0];
                queue2.erase(queue2.begin());
                queue1.push_back(p);
                total1 += p;
                total2 -= p;
                answer++;
            }
        }
        else if (total1 > total2) {
            while (total1 > total2) {
                int p = queue1[0];
                queue1.erase(queue1.begin());
                queue2.push_back(p);
                total2 += p;
                total1 -= p;
                answer++;
            }
        }


        // if(total1 < total2){
        //     int p = queue2[0];
        //     queue2.erase(queue2.begin());
        //     queue1.push_back(p);
        //     total1 += p;
        //     total2 -= p;
        //     answer++;
        // }
        // else if(total1 > total2){
        //     int p = queue1[0];
        //     queue1.erase(queue1.begin());
        //     queue2.push_back(p);
        //     total2 += p;
        //     total1 -= p;
        //     answer++;
        // }
    }

    return answer;
}
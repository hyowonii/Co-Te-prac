/*
코드 출처
https://velog.io/@minsang96/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EB%B3%B4%EC%84%9D-%EC%87%BC%ED%95%91-C
**이해하기**
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> m;

vector<int> solution(vector<string> gems) {
    vector<int> answer = { 1, (int)gems.size() }; // 인덱스를 직접 참조하여 값을 수정하기 위해 초기값을 설정  
    int s = 0; //start 
    int e = 0; //end
    int distance = gems.size() - 1; // end-start의 값으로 가장 작은 구간을 구하기 위한 변수
    map<string, int> m;
    int total;
    for (string i : gems) {
        m[i] += 1;
    }

    total = m.size(); // 보석의 개수를 구한 뒤
    m.clear(); // 맵 초기화

    while (true) {
        if (m.size() == total) { // 모든 보석을 다 구한 경우
            if (e - s < distance) {
                distance = e - s;
                answer[0] = s + 1;
                answer[1] = e;  // e는 하나 증가됐었음
            }

            if (m[gems[s]] == 1) { // 보석의 개수가 1개 일 때
                m.erase(gems[s]);
                s++;
            }
            else { // 보석의 개수가 1개 이상일 때
                m[gems[s]]--;
                s++;
            }
        }
        else if (e == gems.size()) // 끝까지 탐색을 마쳤을때
            break;
        else { // 모든 보석을 아직 찾지 못했을 경우
            m[gems[e]]++;
            e++;
        }

    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> gems;
    gems.push_back("DIA");
    gems.push_back("RUBY");
    gems.push_back("RUBY");
    gems.push_back("SAPPHIRE");
    //gems.push_back("EMERARD");
    gems.push_back("DIA");
    gems.push_back("RUBY");
    gems.push_back("SAPPHIRE");
    gems.push_back("DIA");

    vector<int> result = solution(gems);

    cout << result[0] << ", " << result[1];
}
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <list>
#include <tuple>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    //    string answer = "";

        // 왜 틀린지 몰겠음 ㅠㅠ
    //     bool erased[1000000] = {false};
    //     stack<int> rollback;

    //     for(auto s : cmd){
    //         if(s[0] == 'U'){
    //             int num = stoi(s.substr(2));
    //             while(num > 0){
    //                 k -= 1;
    //                 if(erased[k] == true) continue;
    //                 num--;
    //             }
    //         }
    //         else if(s[0] == 'D'){
    //             int num = stoi(s.substr(2));
    //             while(num > 0){
    //                 k += 1;
    //                 if(erased[k] == true) continue;
    //                 num--;
    //             }
    //         }
    //         else if(s[0] == 'C'){
    //             erased[k] = true;   // 선택 행 삭제
    //             rollback.push(k);
    //             bool bottom = true; // 가장 마지막 행
    //             int kk = k+1;
    //             for(kk; kk<n; kk++){
    //                 if(erased[kk]==true) continue;
    //                 k = kk;
    //                 bottom = false;
    //                 break;
    //             }
    //             if(bottom) k -= 1;
    //         }
    //         else if(s[0] == 'Z'){
    //             erased[rollback.top()] = false;
    //             rollback.pop();
    //         }
    //     }

    //     for(int i=0; i<n; i++){
    //         if(erased[i] == false) answer += "O";
    //         else answer += "X";
    //     }


        // STL list 활용
    list<int> l;
    list<int>::iterator its[1000005];   // 위치 기억
    list<int>::iterator cursor;
    stack<pair<int, int>> erased;

    for (int i = 0; i < n; i++)
        l.push_back(i);
    l.push_back(n);
    auto it = l.begin();
    for (int i = 0; i < n + 1; i++) {
        its[i] = it;
        it++;
    }
    cursor = its[k];
    for (auto s : cmd) {
        if (s[0] == 'U') {
            int num = stoi(s.substr(2, 100));
            while (num--) cursor--;
        }
        else if (s[0] == 'D') {
            int num = stoi(s.substr(2, 100));
            while (num--) cursor++;
        }
        else if (s[0] == 'C') {
            erased.push({ *cursor, *(next(cursor)) });
            cursor = l.erase(cursor);
            if (*cursor == n) cursor--;
        }
        else { // Z
            int cur, nxt;
            tie(cur, nxt) = erased.top();
            erased.pop();
            its[cur] = l.insert(its[nxt], cur);
        }
    }
    string answer(n, 'X');
    for (auto x : l)
        if (x != n) answer[x] = 'O';


    return answer;
}
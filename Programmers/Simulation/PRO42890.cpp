/*
    프로그래머스 [후보키]
    https://school.programmers.co.kr/learn/courses/30/lessons/42890
    구현
    * 테케 9, 11
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<vector<int>> result;
    
    vector<int> v;
    for(int i=0; i<relation[0].size(); i++) 
        v.push_back(i);
    sort(v.begin(), v.end());   // 필요없음 
    
    do {
        
        for(int i=0; i<relation[0].size(); i++) {   // 조합된 개수인데 인덱스
            map<vector<string>, int> m;
            for(int j=0; j<relation.size(); j++) {  
                vector<string> onev;    // 한 조합에 들어가는 원소들 
                for(int k=0; k<=i; k++) {
                    onev.push_back(relation[j][v[k]]);
                }
                sort(onev.begin(), onev.end());
                m[onev]++;
            }
            
            vector<int> temp;   // 조합 인덱스
            for(int k=0; k<=i; k++) temp.push_back(v[k]);
            sort(temp.begin(), temp.end());
            
            if(find(result.begin(), result.end(), temp) != result.end()) continue;  // 중복 방지
            
            result.push_back(temp);
            
            for(auto c : m) {
                if(c.second > 1) {
                    result.pop_back();
                    break;
                }
            }
        }
    }while(next_permutation(v.begin(), v.end()));
    
    // for(auto c : result) {
    //     for(auto i : c) cout<<i<<", ";
    //     cout<<"\n";
    // }
    
    
    // 최소성
    sort(result.begin(), result.end());
    
    for(int s=0; s<result.size(); s++) {
        for(int e=s+1; e<result.size(); e++) {
            vector<int> tmp;
            tmp.resize(result[s].size() + result[e].size());    // 공간확보
            auto iter = set_intersection(result[s].begin(), result[s].end(), result[e].begin(), result[e].end(), tmp.begin());  //교집합
            tmp.erase(iter, tmp.end());
            if(tmp==result[s]) {
                result.erase(result.begin() + e);
                e--;
            }
            else if(tmp==result[e]) {
                result.erase(result.begin() + s);
                s--;
                break;
            }
        }
    }

    // cout<<"결과\n";
    // for(auto c : result) {
    //     for(auto i : c) cout<<i<<", ";
    //     cout<<"\n";
    // }
    
    answer = result.size();
    
    
    return answer;
}


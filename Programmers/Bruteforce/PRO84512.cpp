/*
  프로그래머스 [모음사전]
  https://school.programmers.co.kr/learn/courses/30/lessons/84512
  부르트포스
*/

// version 1
#include <string>
#include <vector>
#include <map>

using namespace std;

string words = "AEIOU";
int answer, cnt;

void dfs(string now, string target){
    if(now == target) answer = cnt;
    if(now.length() > 5) return;
    cnt++;
    for(int i=0; i<words.length(); i++){
        dfs(now + words[i], target);
    }
}

int solution(string word) {
    int answer = 0;
    
    map<char, int> alp;
    alp.insert({'A', 0});
    alp.insert({'E', 1});
    alp.insert({'I', 2});
    alp.insert({'O', 3});
    alp.insert({'U', 4});
    
    int next_word[5] = {781, 156, 31, 6, 1};

    int i=0;
    for(const auto &c : word){
        answer += 1 + alp[c] * next_word[i];
        i++;
    }
    
    
    dfs("", word);
    
    return answer;
}


// version 2
#include <string>
#include <vector>
using namespace std;

string words = "AEIOU";
int answer,cnt;

void dfs(string now, string target)
{
    if (now == target) answer = cnt;
    //word의 길이는 5이하
    if (now.length() > 5) return; 
    cnt++;
    for (int i = 0; i < words.length(); i++)
        dfs(now + words[i], target);
}

int solution(string word) {
    dfs("", word);
    return answer;
}
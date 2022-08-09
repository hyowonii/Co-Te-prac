/*
  프로그래머스 [게임 맵 최단거리]
  https://school.programmers.co.kr/learn/courses/30/lessons/1844
  bfs
*/

#include<vector>
#include <queue>
#include <iostream>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int vis[101][101] = {false};

int solution(vector<vector<int>> maps)
{
    int answer = 1;
    
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<pair<int, int>,int>> Q;  // ((x,y),카운트값)
    Q.push(make_pair(make_pair(0,0),1));  // 초기 위치
    vis[0][0] = true;
    
    while(!Q.empty()) {
        
        auto cur = Q.front(); Q.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int cnt = cur.second;   // answer
        
        if(x==n-1 && y==m-1) return cnt;
        
        for(int i=0; i<4; i++) {
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(maps[nx][ny] == 0 || vis[nx][ny] == true) continue;
            
            Q.push(make_pair(make_pair(nx, ny), cnt+1));
            vis[nx][ny] = true;
        }
    }
    
    
    return -1;
}
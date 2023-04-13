/*
  백준 [퍼즐 조각 채우기]
  https://school.programmers.co.kr/learn/courses/30/lessons/84021
  bfs
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;  // 판 변 길이
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
// 빈 칸 저장
vector<vector<pair<int,int>>> avi;
vector<vector<pair<int,int>>> figure;

bool overRange(int x, int y){
    if(x<0 || x>=n || y<0 || y>=n) return true;
    return false;
}

// 크기순 나열
bool compare(vector<pair<int,int>> v1, vector<pair<int,int>> v2){
    return v1.size() < v2.size();
}

// 회전
vector<pair<int,int>> Rotate(vector<pair<int,int>> f){
    vector<pair<int,int>> tmp;
    for(int i=0; i<f.size(); i++){
        int ni = f[i].second;
        int nj = f[i].first * (-1);
        tmp.push_back({ni,nj});
    }
    sort(tmp.begin(), tmp.end());
    return tmp;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    n = table.size(); 
    
    // 빈칸 저장하기
    bool vis[51][51] = {false};
    bool vis2[51][51] = {false};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(game_board[i][j] != 1 && !vis[i][j]){
                vector<pair<int,int>> v;
                v.push_back({0,0}); // 기준점

                queue<pair<int, int>> q;
                q.push({i,j});
                vis[i][j] = true;

                while(!q.empty()){
                    auto cur = q.front();   q.pop();
                    for(int k=0; k<4; k++){
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if(overRange(nx,ny)) continue;
                        if(game_board[nx][ny] == 1) continue;
                        if(vis[nx][ny]) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                        v.push_back({nx-i, ny-j});  // 기준점과의 차이만큼
                    }
                }
                avi.push_back(v);
            }
            
            
            if(table[i][j] != 0 && !vis2[i][j]){
                // 1.
                vector<pair<int,int>> v2;    // 찾은 모형
                v2.push_back({0,0}); // 기준점

                queue<pair<int, int>> q2;
                q2.push({i,j});
                vis2[i][j] = true;

                while(!q2.empty()){
                    auto cur = q2.front();   q2.pop();
                    for(int k=0; k<4; k++){
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if(overRange(nx,ny)) continue;
                        if(table[nx][ny] == 0) continue;
                        if(vis2[nx][ny]) continue;
                        q2.push({nx, ny});
                        vis2[nx][ny] = true;
                        v2.push_back({nx-i, ny-j});  // 기준점과의 차이만큼
                    }
                }
                figure.push_back(v2);    
            }
        }
    }
    sort(avi.begin(), avi.end(), compare);
    sort(figure.begin(), figure.end(), compare);
    
    
    // 2.
    for(int i=0; i<avi.size(); i++){
        auto a = avi[i];    // 빈 곳
        for(int j=0; j<figure.size(); j++){
            auto f = figure[j]; // 도형
            if(a.size() != f.size()) continue;  // 애초에 칸수부터 안맞으면 패쓰
            sort(a.begin(), a.end());
            bool flag = true;
            for(int rotate=0; rotate<4; rotate++){  // 회전
                f = Rotate(f);
                int diffx = a[0].first - f[0].first;
                int diffy = a[0].second - f[0].second;
                flag = true;
                for(int k=1; k<a.size(); k++){
                    int diffxx = a[k].first - f[k].first;
                    int diffyy = a[k].second - f[k].second;
                    if(diffx != diffxx || diffy != diffyy){
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    answer += a.size();
                    figure.erase(figure.begin() + j);
                    break;
                }
            }
            if(flag) break;
        }
    }
    
    
    return answer;
}
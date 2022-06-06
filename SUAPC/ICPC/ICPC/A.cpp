#include<iostream>
#include<vector>

#define MAX 200000
using namespace std;

const int MOD = 1000000007;
int visited[MAX];
int graph[MAX][MAX];
int m, n; //교육생수,친분관계수

void dfs(int x, int group_num) {
    visited[x] = group_num;// visited배열에 몇번째 그룹에 속하는지 표시

    //cout << x;
    for (int i = 1; i <= m; i++) {
        if (graph[x][i] && !visited[i]) {
            dfs(i, group_num);
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int group = 0;  //그룹수
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        graph[from][to] = 1;
        graph[to][from] = 1;
    }


    int group_num = 1;
    for (int i = 1; i <= m; i++) {
        /*
        for (int i = 1; i <= m; i++)
            cout << visited[i];
        cout <<"\n";
        */
        if (!visited[i]) {
            dfs(i, group_num);
            group_num++;
            group++;
        }
    }


    int ans = 1; //총 경우의 수
    vector<int> count(group_num); //idx번째 그룹에 몇명이 있는지

    for (int i = 1; i <= m; i++) {
        count[visited[i]]++;
    }


    for (int i = 1; i < count.size(); i++) {
        //cout << count[i] << ' ';
        ans *= count[i];
        ans %= MOD;
    }


    cout << ans;

    return 0;
}
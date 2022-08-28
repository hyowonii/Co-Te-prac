/*
  백준 [국영수]
  https://www.acmicpc.net/problem/10825
  정렬
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
  string name;
  int K, E, M;
};

bool compare(Student A, Student B) {
  if(A.K == B.K) {
    if(A.E == B.E) {
      if(A.M == B.M) {
        return A.name < B.name;
      }
      else return A.M > B.M;
    }
    else return A.E < B.E;
  }
  else return A.K > B.K;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  vector<Student> list(N);

  for(int i=0; i<N; i++) {
    cin >> list[i].name >> list[i].K >> list[i].E >> list[i].M;
  }

  sort(list.begin(), list.end(), compare);

  for(int i=0; i<N; i++) {
    cout << list[i].name << "\n";
  }

}
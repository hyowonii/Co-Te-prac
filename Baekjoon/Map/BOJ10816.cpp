#include <iostream>
#include <map>

using namespace std;

int n;
map<long long, int> nums;
int m;

void init() {
  cin >> n;
  while(n--){
    long long num;
    cin >> num;
    nums[num]++;
  }
  cin >> m;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  init();

  while(m--){
    long long num;
    cin >> num;
    cout << nums[num] << " ";
  }

  return 0;
}
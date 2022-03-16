#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> m1;
map<string, string> m2;
int result = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string start, end, stream;
	cin >> start >> end >> stream;

	int start_h = stoi(start.substr(0, 2));
	int start_m = stoi(start.substr(3, 2));
	int end_h = stoi(end.substr(0, 2));
	int end_m = stoi(end.substr(3, 2));
	int stream_h = stoi(stream.substr(0, 2));
	int stream_m = stoi(stream.substr(3, 2));

	string time;
	string name;
	while (cin >> time >> name) {

		if (stoi(time.substr(0, 2)) <= start_h) {

			if (stoi(time.substr(0, 2)) == start_h && stoi(time.substr(3, 2)) > start_m) continue;

			m1.insert({ name, time });
		}
		else if (stoi(time.substr(0, 2)) >= end_h && stoi(time.substr(0, 2)) <= stream_h) {

			if (stoi(time.substr(0, 2)) == end_h && stoi(time.substr(3, 2)) < end_m) continue;
			if (stoi(time.substr(0, 2)) == stream_h && stoi(time.substr(3, 2)) > stream_m) continue;

			if (m1.find(name) != m1.end()) {
				m2.insert({ name, time });
			}
		}
	}

	cout << m2.size();

	//////////////////////////////////////////////////////////////////////////////////////////////
	
	typedef pair <bool, bool> cb;

	string str1, str2, str3;

	cin >> str1 >> str2 >> str3;

	// ***********************
	int start_opening = stoi(str1.substr(0, 2)) * 60 + stoi(str1.substr(3, 2));
	int end_opening = stoi(str2.substr(0, 2)) * 60 + stoi(str2.substr(3, 2));
	int end_streaming = stoi(str3.substr(0, 2)) * 60 + stoi(str3.substr(3, 2));

	string time_str, name;

	map <string, cb> check;

	while (cin >> time_str >> name) {

		int time = stoi(time_str.substr(0, 2)) * 60 + stoi(time_str.substr(3, 2));

		if (time <= start_opening) {
			check[name].first = true; //입장체크
		}
		else if (time >= end_opening && time <= end_streaming) {
			check[name].second = true; //퇴장체크
		}
	}

	int ans = 0;
	for (auto iter : check) {
		if (iter.second.first && iter.second.second) { // 입장 + 퇴장 체크 모두 완료되었다면
			ans++;
		}
	}

	cout << ans;
}
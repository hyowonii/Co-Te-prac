#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    vector<pair<int, int>> board;
    board.push_back({ 3,1 });
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board.push_back({ i, j });
        }
    }

    pair<int, int> lidx = { 3,0 };
    pair<int, int> ridx = { 3,2 };

    for (auto num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            answer += "L";
            lidx = board[num];
        }
        else if (num == 3 || num == 6 || num == 9) {
            answer += "R";
            ridx = board[num];
        }
        else {   // 2,5,8,0
            pair<int, int> loc = board[num];
            int ldir = abs(lidx.first - loc.first) + abs(lidx.second - loc.second);
            int rdir = abs(ridx.first - loc.first) + abs(ridx.second - loc.second);
            if (ldir < rdir || (ldir == rdir && hand == "left")) {
                answer += "L";
                lidx = loc;
            }
            else if (ldir > rdir || (ldir == rdir && hand == "right")) {
                answer += "R";
                ridx = loc;
            }
        }
    }

    return answer;
}
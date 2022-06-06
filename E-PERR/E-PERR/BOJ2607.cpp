#include <iostream>
using namespace std;
#include <cstring>
#include <vector>

void counting(int freq[26], string word) {
	for (int i = 0; i < word.length(); i++) 
		freq[word[i] - 'A']++;
}

int solution(int n, vector<string> words) {

	int freq_firstword[26] = { 0 }, freq_other[26] = { 0 };	// �� ���ĺ� �� ���� �迭
	counting(freq_firstword, words[0]);

	int length = words[0].length();	// ù��° �ܾ� ����
	int diff;	// �� �ܾ��� ���ĺ��� �ٸ� ����

	int answer = 0;
	for (int i = 1; i < n; i++) {

		diff = 0;
		memset(freq_other, 0x0, 26 * sizeof(int));	// �迭 �ʱ�ȭ
		counting(freq_other, words[i]);

		for (int k = 0; k < 26; k++) 
			diff += abs(freq_other[k] - freq_firstword[k]);

		if (diff == 0 || diff == 1 || (diff == 2 && (words[i].length() == length)))
			answer++;
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int answer = 0;

	cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; i++) 
		cin >> words[i];
	
	answer = solution(n, words);
	cout << answer;

}
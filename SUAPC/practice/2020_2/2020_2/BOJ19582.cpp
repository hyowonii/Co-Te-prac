#include <iostream>
#include <vector>

using namespace std;


typedef pair<int, int> ci;


int tryAll(int n, vector<ci> contest) {

	long long sum = 0; //��� ��

	//ó������ ��� ���ѿ� �ɷ� ������ �Ұ������� ��ȸ ã�� - idx��°
	for (int i = 0; i < n - 2; i++) {

		if (sum + contest[i].second > contest[i + 1].first) { //�̹� ��ȸ����� ������ ������ȸ�� �������� �ȴٸ�
			return i + 1; //�������� ��ȸ �ε��� ��ȯ
		}

		sum += contest[i].second;

	}

	return -1; //-1 �ϰ�� ���� �Ѱ�.

}

// idx��° ��ȸ�� ���� �����غ���.
bool exceptIdx(int n, vector<ci> contest, int idx) {

	long long sum = 0;
	for (int i = 0; i < n; i++) {

		if (i == idx)
			continue;

		if (sum > contest[i].first) { //���� ���� ���� ����� �̹���ȸ�� ����������Ǻ��� ũ�ٸ�
			return false;

		}
		sum += contest[i].second;

	}

	return true;

}

// idx��° ��ȸ ������ ���� ��ȸ �� �޴� ����� ���� ū ��ȸ�� ���, �� ��ȸ�� �����غ���
bool exceptLargestBeforeIdx(int n, vector<ci> contest, int idx) {

	int largest_reward = -1;
	int largest_idx;// ���� ����� ū ��ȸ�� �ε���

	for (int i = 0; i < idx; i++) {

		if (largest_reward < contest[i].second) {
			largest_idx = i;
			largest_reward = contest[i].second;
		}

	}

	return  exceptIdx(n, contest, largest_idx);
}

int main() {


	int n;
	cin >> n;

	vector<ci> contest(n, { 0,0 }); // first : �������� , second : ���

	for (int i = 0; i < n; i++) {
		cin >> contest[i].first >> contest[i].second;
	}


	int result = tryAll(n, contest);


	if (result == -1) { //��� ��ȸ ���� ������
		cout << "Kkeo-eok";
	}
	else {

		if (exceptIdx(n, contest, result)) {
			cout << "Kkeo-eok";
		}
		else {

			if (exceptLargestBeforeIdx(n, contest, result)) {
				cout << "Kkeo-eok";
			}
			else
				cout << "Zzz";

		}

	}

}
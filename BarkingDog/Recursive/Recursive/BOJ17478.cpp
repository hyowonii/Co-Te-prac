#include <iostream>

using namespace std;

int N;

void _bar(const char* str, int stk) {
	for (int i = 0; i < stk; i++) cout << "____";
	cout << str;
}

void recursion(int cnt) {
	_bar("\"����Լ��� ������?\"\n", cnt);
	if (cnt == N) _bar("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n", cnt);
	else {
		_bar("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n", cnt);
		_bar("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n", cnt);
		_bar("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n", cnt);
		recursion(cnt + 1);
	}
	_bar("��� �亯�Ͽ���.\n", cnt);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	recursion(0);
}
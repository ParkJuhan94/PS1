#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dy[21][21];	//	�޸������̼��� ���� 2�����迭 : n�� r�̴ϱ�

int DFS(int n, int r) {
	if (dy[n][r] > 0) return dy[n][r];	//	�޸������̼� Ȱ��

	if (n == r || r == 0) return 1;		//	��������
	else return dy[n][r] = DFS(n - 1, r) + DFS(n - 1, r - 1);	//	�����ϸ鼭 �޸������̼� ����ϱ�
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, r;
	scanf("%d %d", &n, &r);

	printf("%d\n", DFS(n, r));
	return 0;
}
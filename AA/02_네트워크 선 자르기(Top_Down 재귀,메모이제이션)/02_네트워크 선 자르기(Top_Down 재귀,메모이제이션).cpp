//	Top-Down
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int dy[101];

int DFS(int n) {
	if (dy[n] > 0) return dy[n];	//	���ʿ��� ����� �����ϵ���. �޸������̼�

	if (n == 1 || n == 2) {
		return n;
	}
	else {
		return dy[n] = DFS(n - 2) + DFS(n - 1);		//	dy[n]�� ���Ǹ鼭 ���ÿ� return
	}
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", DFS(n));
}
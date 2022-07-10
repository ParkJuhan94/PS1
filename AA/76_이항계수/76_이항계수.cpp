#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dy[21][21];	//	메모이제이션을 위한 2차원배열 : n와 r이니까

int DFS(int n, int r) {
	if (dy[n][r] > 0) return dy[n][r];	//	메모이제이션 활용

	if (n == r || r == 0) return 1;		//	종착지점
	else return dy[n][r] = DFS(n - 1, r) + DFS(n - 1, r - 1);	//	리턴하면서 메모이제이션 기록하기
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, r;
	scanf("%d %d", &n, &r);

	printf("%d\n", DFS(n, r));
	return 0;
}
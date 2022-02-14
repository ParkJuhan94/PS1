//	Top-Down
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int dy[101];

int DFS(int n) {
	if (dy[n] > 0) return dy[n];	//	불필요한 계산을 생략하도록. 메모이제이션

	if (n == 1 || n == 2) {
		return n;
	}
	else {
		return dy[n] = DFS(n - 2) + DFS(n - 1);		//	dy[n]이 계산되면서 동시에 return
	}
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", DFS(n));
}
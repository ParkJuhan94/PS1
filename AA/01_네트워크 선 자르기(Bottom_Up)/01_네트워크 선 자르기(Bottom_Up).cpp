//	Buttom-Up
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int dy[50];

int main() {
	int n;
	scanf("%d", &n);

	dy[1] = 1;
	dy[2] = 2;	//1 1 . 2

	// 4 -> - - - -) -> dy [4] = dy [3] + dy [2]
	for (int i = 3; i <= n; i++) {
		dy[i] = dy[i - 2] + dy[i - 1];
	}

	printf("%d\n", dy[n]);
}
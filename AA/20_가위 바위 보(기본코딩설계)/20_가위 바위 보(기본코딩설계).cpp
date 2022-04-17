#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

void printWinner(int a, int b) {
	if (a == 1) {
		if (b == 1) {
			printf("D\n");
		}
		else if (b == 2) {
			printf("B\n");
		}
		else if (b == 3) {
			printf("A\n");
		}
	}
	else if (a == 2) {
		if (b == 1) {
			printf("A\n");
		}
		else if (b == 2) {
			printf("D\n");
		}
		else if (b == 3) {
			printf("B\n");
		}
	}
	else if (a == 3) {
		if (b == 1) {
			printf("B\n");
		}
		else if (b == 2) {
			printf("A\n");
		}
		else if (b == 3) {
			printf("D\n");
		}
	}
}

int main() {
	int n;
	int a[100];
	int b[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);		
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}

	for (int i = 0; i < n; i++) {
		printWinner(a[i], b[i]);
	}
}
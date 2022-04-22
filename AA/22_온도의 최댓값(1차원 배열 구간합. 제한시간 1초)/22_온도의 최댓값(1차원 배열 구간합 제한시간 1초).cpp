#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

int main(){
	int n, m, max = 0, sum, i, j;
	int* arr;

	scanf("%d %d", &n, &m);
	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < n - m + 1; i++) {
		sum = 0;
		for (j = i; j < i + m; j++) {
			sum += j;
			if (sum > max) {
				max = sum;
			}
		}
	}
	printf("%d\n", sum);
}
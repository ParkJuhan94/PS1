#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>

int main() {
	int n, m, max, sum = 0, i, j;
	
	scanf("%d %d", &n, &m);
	std::vector<int> arr(n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < m; i++) {
		sum += arr[i];
	}	

	max = sum;
	
	//	���� �а� ������
	for (i = m; i < n; i++) {		
		sum += arr[i];
		sum -= arr[i - m];
		if (sum > max) {
			max = sum;
		}
	}
	printf("%d\n", max);
}

/* O �� n^2 �̶� time limit �ɸ��� �ڵ�
int main() {
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
			sum += arr[j];
		}
		if (sum > max) {
			max = sum;
		}
	}
	printf("%d\n", max);
}
*/
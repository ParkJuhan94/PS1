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
	
	//	이제 밀고 나가기
	for (i = m; i < n; i++) {		
		sum += arr[i];
		sum -= arr[i - m];
		if (sum > max) {
			max = sum;
		}
	}
	printf("%d\n", max);
}

/* O 의 n^2 이라서 time limit 걸리는 코드
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
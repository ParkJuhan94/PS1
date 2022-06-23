#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std; 

// 내 코드
int main() {
	int i = 2, j, sum = 0, a, n;

	scanf("%d", &n);
	while (true) {
		sum = 0;
		for (j = 1; j <= i; j++) {
			sum += j;
		}

		if (sum > n) break;

		if ((n - sum) % i == 0) {
			a = (n - sum) / i;

			for (j = 1; j < i; j++) {
				printf("%d + ", a + j);
			}
			printf("%d = %d \n", a + j, n);
		}
		i++;
	}
}

/*
//	강사님 코드

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int a, b = 1, cnt = 0, tmp, i;
	scanf("%d", &a);
	tmp = a;
	a--;
	while (a > 0) {
		b++;
		a = a - b;
		if (a % b == 0) {
			for (i = 1; i < b; i++) {
				printf("%d + ", (a / b) + i);
			}
			printf("%d = %d\n", (a / b) + i, tmp);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
*/



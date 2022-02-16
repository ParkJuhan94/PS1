#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

int main() {
	int n, m;
	int a, cnt = 0, max = 0;
	int i;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a > m) {
			cnt++;
			if (cnt > max) {
				max = cnt;
			}
		}
		else {
			cnt = 0;
		}
	}

	if (max == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", max);
	}
	
}
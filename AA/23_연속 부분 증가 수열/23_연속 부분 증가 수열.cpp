#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>

int main() {
	int i, n, cnt = 1, maxLen = 0, pre, now, tempi;

	scanf("%d", &n);
	scanf("%d", &pre);

	for (i = 2; i <= n; i++) {
		scanf("%d", &now);
		if (now >= pre) {
			cnt++;			

			if (cnt > maxLen) {
				maxLen = cnt;
			}
		}
		else {
			cnt = 1;
		}
		pre = now;
	}
	printf("%d", maxLen);
}

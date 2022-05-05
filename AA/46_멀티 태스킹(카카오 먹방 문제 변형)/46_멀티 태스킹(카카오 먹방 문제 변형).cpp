#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int a[2001];
int main() {
	int n, k, i, pos = 0, cnt = 0, tot = 0;

	scanf("%d", &n);

	for (i = 1; i <= n;i++) {
		scanf("%d", &a[i]);
		tot += a[i];
	}
	scanf("%d", &k);
	if (k >= tot) {
		printf("-1\n");
		return 0;
	}

	while (1) {
		pos++;
		if (pos > n) pos = 1;

		if (a[pos] == 0) continue;

		a[pos]--;
		cnt++;

		if (cnt == k) break;
	}

	while (1) {
		pos++;
		if (pos > n) pos = 1;

		if (a[pos] != 0) {
			printf("%d\n", pos);
			break;
		}
	}
}


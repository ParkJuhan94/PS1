#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, i, j, pos;
	scanf("%d", &n);
	vector<int> is(n + 1), os(n + 1);

	for (i = 1; i <= n; i++) {
		scanf("%d", &is[i]);
	}

	for (i = n; i >= 1; i--) {
		pos = i;
		for (j = 1; j <= is[i]; j++) {
			os[pos] = os[pos + 1];
			pos++;
		}
		os[pos] = i;
	}

	for (i = 1; i <= n; i++) {
		printf("%d ", os[i]);
	}
	return 0;
}

/* ³»ÄÚµå
int main() {
	int i, j, n, cnt = 0;
	scanf("%d", &n);
	vector<int> is(n);
	vector<int> os(n);

	for (i = 0; i < n; i++) {
		scanf("%d", &is[i]);
	}

	for (i = n - 1; i >= 0; i--) {
		for (j = i; j < i + is[i]; j++) {
			os[j] = os[j + 1];
		}
		os[j] = i + 1;
	}

	for (i = 0; i < n; i++) {
		printf("%d ", os[i]);
	}
}
*/

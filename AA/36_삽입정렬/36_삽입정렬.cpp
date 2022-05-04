#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

//	삽입정렬은 매우 중요함. 기업에서 손코딩 시킨다.
int main() {
	//freopen("input.txt", "rt", stdin);
	int a[100], n, tmp, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 1; i < n; i++) {
		tmp = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (a[j] > tmp) a[j + 1] = a[j];
			else break;
		}
		a[j + 1] = tmp;
	}
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
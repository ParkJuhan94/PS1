#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

int main() {
	int stu[100];
	int n;
	int max = 0, cnt = 0;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &stu[i]);
	}

	for (i = n - 1; i >= 0; i--) {
		if (stu[i] > max ) {
			max = stu[i];
			cnt++;
		}
	}
	cnt--;	//	마지막 학생의 카운팅 상쇄

	printf("%d", cnt);
}
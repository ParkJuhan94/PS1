#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

int main() {
	int i, a[10], b[10], as = 0, bs = 0, lw = 0;
	//	as�� a�� �� ����. bs�� b�� �� ����. 
	//	lw�� last winner(a�̸� lw = 1 / b�̸� lw = 2 / ��� ���带 ����� ���� �ʱ�ȭ�� 0�� �״��)

	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);		
	}
	for (i = 0; i < 10; i++) {
		scanf("%d", &b[i]);		
	}

	for (i = 0; i < 10; i++) {
		if (a[i] > b[i]) {
			as += 3;
			lw = 1;
		}
		else if (a[i] < b[i]) {
			bs += 3;
			lw = 2;
		}
		else {
			as += 1;
			bs += 1;
		}
	}

	printf("%d %d\n", as, bs);

	if (as == bs) {
		if (lw == 0) {
			printf("D");
		}
		else if (lw == 1) {
			printf("A");
		}
		else if (lw == 2) {
			printf("B");
		}
	}
	else if (as > bs) {
		printf("A");
	}
	else if (as < bs) {
		printf("B");
	}


}
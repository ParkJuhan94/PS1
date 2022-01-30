#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, i, cnt = 0, tmp;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		tmp = i;
		while (tmp > 0) {
			tmp = tmp / 10;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}

/*
* 나의 풀이

int numDigit(int x) {
	int cnt = 0;

	while (x > 0) {
		x /= 10;
		cnt++;
	}

	return cnt;
}

int main() {
	int n,i, sum=0;
	scanf("%d", &n); 

	for (i = 1; i <= n; i++) {
		sum += numDigit(i);
	}
	printf("%d\n", sum);
}
*/
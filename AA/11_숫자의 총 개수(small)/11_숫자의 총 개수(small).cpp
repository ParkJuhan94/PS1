#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

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
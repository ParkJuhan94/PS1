#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>			
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, i, j, flag, cnt = 0;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		flag = 1;							//	flag를 건드렸냐? 를 통해서 소수의 개수를 카운팅 한다.
		for (j = 2; j * j <= i; j++) {		//	해당 수의 제곱근 까지만 돌면 소수 판별 가능하다.
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}

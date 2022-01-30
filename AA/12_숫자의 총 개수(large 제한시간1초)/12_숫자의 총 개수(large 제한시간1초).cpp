//어려웠음!!
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);	
	//	n이 256일 때:  
	//	sum  d  c  res
	//	0 +  9 *1  9
	//  9 + 90 *2  189
	//	99 + 900 < 256  (false)
	//	-> res = 189 + (256 - 99) * 3

	int n, sum = 0, cnt = 1, digit = 9, res = 0;		
	scanf("%d", &n);

	while (sum + digit < n) {
		sum = sum + digit;
		res = res + (cnt * digit);		
		cnt++;	
		digit = digit * 10;
	}
	res = res + ((n - sum) * cnt);
	printf("%d\n", res);
	return 0;
}

/*
*	나의 풀이
* 
int numDigit(int x) { 
	int cnt = 0;

	while (x > 0) {
		x /= 10;
		cnt++;
	}

	return cnt;
}

int main() {
	long n, i;
	long sum = 0;
	long min = 1;	//	직전 자릿수와의 경계값
	long arr[10] = {0, 0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889};	//	직전 자릿수까지의 갯수 미리 저장. [0] 자리수와 [1] 자리수는 0
	scanf("%ld", &n);

	int nDigit = numDigit(n);
	for (i = 0; i < nDigit - 1; i++) {
		min *= 10;
	}
	sum += arr[nDigit];
	sum += nDigit * (n - min + 1);

	printf("%ld\n", sum);
}
*/
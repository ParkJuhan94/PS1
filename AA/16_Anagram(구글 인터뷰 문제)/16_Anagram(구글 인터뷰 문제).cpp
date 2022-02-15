#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>	//	exit(0)
//	'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
//	인덱스 1~26은 대문자 카운트, 인덱스 27~52는 소문자 카운트
int a[60] = { 0 }, b[60] = { 0 };

int main() {
	int i;
	char str[101];

	scanf("%s", str);
	
	for (i = 0; str[i] != 0; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {	//	대문자일 때
			a[str[i] - 64]++;	
		}
		else {
			a[str[i] - 70]++;					//	소문자일 때
		}
	}

	scanf("%s", str);

	for (i = 0; str[i] != 0; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {	//	대문자일 때
			b[str[i] - 64]++;
		}
		else {
			b[str[i] - 70]++;					//	소문자일 때
		}
	}

	for (i = 1; i <= 52; i++) {
		if (a[i] != b[i]) {
			printf("NO\n");
			exit(0);
		}
	}
	printf("YES\n");
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

int main() {
	char a[101];
	char b[101];
	int idx = 0;

	//공백 포함한 문자열 입력 받는 법
	scanf("%[^\n]", a);
	
	//공백 제거
	for (int i = 0; a[i] != 0; i++) {
		if (a[i] != ' ') {
			b[idx] = a[i];
			idx++;
		}
	}
	b[idx] = 0;		//마지막 널문자

	//대문자를 소문자로 변환.
	for (int i = 0; b[i] != 0; i++) {
		if ('A' <= b[i] && b[i] <= 'Z') {
			b[i] += 32;		//'a' = 97 'A' = 65
		}
	}

	printf("%s\n", b);
}


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

/*	선생님 코드

#include<stdio.h>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	char a[101], b[101];
	int i, p=0;
	gets(a);
	for(i=0; a[i]!='\0'; i++){
		if(a[i]!=' '){
			if(a[i]>=65 && a[i]<=90){
				b[p++]=a[i]+32;
			}
			else b[p++]=a[i];
		}
	}
	b[p]='\0';
	printf("%s\n", b);
	return 0;
}

*/
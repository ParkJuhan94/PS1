//	스택을 이용한 풀이가 베스트
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

int main() {
	char a[31];
	int flag = 0;
	int i;
	scanf("%s", &a);

	for (i = 0; a[i] != 0; i++) {
		if (a[i] == '(') {
			flag++;
		}
		else if (a[i] == ')') {
			flag--;
		}
	}

	//	나의 틀린 알고리즘.
	//	처음과 끝의 괄호만 생각하면 안돼 
	//	-> 탐색 도중에 '(' 갯수보다 ')' 갯수가 많아지면 브레이크 해야해
	if (flag != 0 || a[0] == ')' || a[i - 1] == '(') {
		printf("NO\n");
	}
	else {
		printf("YES\n");
	}
}

/*	선생님 코드

#include<stdio.h>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	char a[100];
	int i, cnt=0;
	scanf("%s", &a);
	for(i=0; a[i]!='\0'; i++){
		if(a[i]=='(') cnt++;
		else if(a[i]==')') cnt--;
		if(cnt<0) break;	//	중요
	}
	if(cnt==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
*/
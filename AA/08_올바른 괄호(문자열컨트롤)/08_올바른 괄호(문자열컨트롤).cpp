//	������ �̿��� Ǯ�̰� ����Ʈ
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

	//	���� Ʋ�� �˰���.
	//	ó���� ���� ��ȣ�� �����ϸ� �ȵ� 
	//	-> Ž�� ���߿� '(' �������� ')' ������ �������� �극��ũ �ؾ���
	if (flag != 0 || a[0] == ')' || a[i - 1] == '(') {
		printf("NO\n");
	}
	else {
		printf("YES\n");
	}
}

/*	������ �ڵ�

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
		if(cnt<0) break;	//	�߿�
	}
	if(cnt==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
*/
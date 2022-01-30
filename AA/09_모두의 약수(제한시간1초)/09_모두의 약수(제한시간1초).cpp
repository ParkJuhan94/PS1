#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

int cnt[50001];		//	���������� ������ �ڵ����� 0���� �ʱ�ȭ��

//	Ÿ�Ӹ����� ����Ͽ� �ð����⵵�� n*logn ���Ϸ� ��ƾ���
//	1���� n���� ���鼭 �ڽ��� ����� ī������ ���ִ� �˰���(�̶� j += i �� �����ؾ���)
int main() {
	int n, i, j;	

	scanf("%d", &n);
	
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j += i) {	//i�� 3�϶� cnt[3],cnt[6],cnt[9],,,�� ++
			cnt[j]++;
		}
	}

	for (i = 1; i <= n; i++) {
		printf("%d ", cnt[i]);
	}
}



/*
	�ð����⵵�� n^2 �̶� n�� 30000�� �Ѿ�� 1�� �̻�ɸ�. Ÿ�� ����

int main(){
	int n, i, j;
	int cnt = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		cnt = 0;	
		for (j = 1; j <= i; j++) {
			if (i % j == 0) cnt++;			
		}
		printf("%d ", cnt);
	}
}

*/


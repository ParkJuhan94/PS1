#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

int main() {
	char a[101];
	char b[101];
	int idx = 0;

	//���� ������ ���ڿ� �Է� �޴� ��
	scanf("%[^\n]", a);
	
	//���� ����
	for (int i = 0; a[i] != 0; i++) {
		if (a[i] != ' ') {
			b[idx] = a[i];
			idx++;
		}
	}
	b[idx] = 0;		//������ �ι���

	//�빮�ڸ� �ҹ��ڷ� ��ȯ.
	for (int i = 0; b[i] != 0; i++) {
		if ('A' <= b[i] && b[i] <= 'Z') {
			b[i] += 32;		//'a' = 97 'A' = 65
		}
	}

	printf("%s\n", b);
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>	//	exit(0)
//	'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
//	�ε��� 1~26�� �빮�� ī��Ʈ, �ε��� 27~52�� �ҹ��� ī��Ʈ
int a[60] = { 0 }, b[60] = { 0 };

int main() {
	int i;
	char str[101];

	scanf("%s", str);
	
	for (i = 0; str[i] != 0; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {	//	�빮���� ��
			a[str[i] - 64]++;	
		}
		else {
			a[str[i] - 70]++;					//	�ҹ����� ��
		}
	}

	scanf("%s", str);

	for (i = 0; str[i] != 0; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {	//	�빮���� ��
			b[str[i] - 64]++;
		}
		else {
			b[str[i] - 70]++;					//	�ҹ����� ��
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
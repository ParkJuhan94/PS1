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

	if (flag != 0 || a[0] == ')' || a[i - 1] == '(') {
		printf("NO\n");
	}
	else {
		printf("YES\n");
	}
}


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>			
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, i, j, flag, cnt = 0;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		flag = 1;							//	flag�� �ǵ�ȳ�? �� ���ؼ� �Ҽ��� ������ ī���� �Ѵ�.
		for (j = 2; j * j <= i; j++) {		//	�ش� ���� ������ ������ ���� �Ҽ� �Ǻ� �����ϴ�.
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}

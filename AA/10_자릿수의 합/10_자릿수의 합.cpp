#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

int digit_sum(int x) {
	int sum = 0, tmp;
	while (x > 0) {
		tmp = x % 10;
		sum = sum + tmp;
		x = x / 10;
	}
	return sum;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, num, i, sum, max = -2147000000, res;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &num);
		sum = digit_sum(num);
		if (sum > max) {
			max = sum;
			res = num;
		}
		else if (sum == max) {
			if (num > res) res = num;
		}
	}
	printf("%d\n", res);
	return 0;
}


/*
	���� Ǯ��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

int num[100];	//	�ڿ����� ����
int sum[100];	//	�ڿ����� �ڸ����� ���� ����

int digit_sum(int x) {
	int res = 0;

	while ( x > 0) {
		res += x % 10;
		x /= 10;
	}

	return res;
}

int main() {
	int n, i, max=0;	//	max�� �� �� ���δ�.
	int idx;			//	�ڸ����� ���� �ִ밡 �Ǵ� index�� ����
	int idx_max;		//	sum[idx]�� ���� sum ���� ���� �� �߿��� ���� ū ���� index�� ����
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	for (i = 0; i < n; i++) {
		sum[i] = digit_sum(num[i]);
	}

	for (i = 0; i < n; i++) {
		if (sum[i] >= max) {
			max = sum[i];
			idx = i;
		}
	}

	max = num[idx];
	for (i = 0; i < n; i++) {
		if (sum[i] == sum[idx]) {
			if (num[i] > max) {
				max = num[i];
			}
		}
	}

	printf("%d\n", max);
}
*/
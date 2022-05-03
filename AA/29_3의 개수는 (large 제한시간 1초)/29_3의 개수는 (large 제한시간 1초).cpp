#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, left = 77, right, cur, k = 1, res = 0;
	scanf("%d", &n);
	while (left != 0) {
		left = n / (k * 10);
		right = n % k;
		cur = (n / k) % 10;
		//	cur과 3의 대소비교를 통해서 3가지 케이스를 나눈다
		if (3 < cur) {
			res = res + ((left + 1) * k);
		}
		else if (3 == cur) {
			res = res + ((left * k) + (right + 1));
		}
		else res = res + (left * k);
		k = k * 10;
	}
	printf("%d\n", res);
	return 0;
}

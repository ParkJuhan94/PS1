#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, i, j;
	scanf("%d", &n);
	vector<int> a(n);	//	점수
	vector<int> b(n, 1);	//	등수. 1로 초기화

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);		
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i] < a[j]) {
				b[i]++;
			}
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d ", b[i]);
	}
}
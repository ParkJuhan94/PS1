#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, idx, i, j, tmp;

	scanf("%d", &n);
	vector<int> a(n); 
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	//	��������. ������������\
	//	�� �������� ������ �ϳ��� �������
	for (i = 0; i < n - 1; i++) {
		idx = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[idx]) {
				idx = j;
			}
		}
		tmp = a[i];
		a[i] = a[idx];
		a[idx] = tmp;		
	}

	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}
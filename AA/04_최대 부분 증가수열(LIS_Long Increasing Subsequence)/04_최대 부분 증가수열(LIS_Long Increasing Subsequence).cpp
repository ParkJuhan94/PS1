#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, res = 0;
	scanf("%d", &n);
	vector<int> arr(n+1), dy(n + 1);	//	�迭�� ��� ���Ұ� 0���� �ʱ�ȭ��

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dy[1] = 1;

	for (int i = 2; i <= n; i++) {
		int max = 0;

		for (int j = i - 1; j >= 1; j--) {		
			if (arr[j] < arr[i] && dy[j] > max) {
				max = dy[j];
			}
		}
		dy[i] = max + 1;

		if (dy[i] > res) {
			res = dy[i];
		}
	}
	cout << res;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int s, n, i, j, pos = -1, a;

	scanf("%d %d", &s, &n);
	vector<int> c(s);	

	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		pos = -1;
		for (j = 0; j < s; j++) {
			if (c[j] == a) {
				pos = j;
			}			
		}
		
		if (pos == -1) {
			for (j = s - 2; j >= 0; j--) {
				c[j + 1] = c[j];
			}
			c[0] = a;
		}
		else {
			for (j = pos - 1; j >= 0; j--) {
				c[j + 1] = c[j];
			}
			c[0] = a;
		}
	}

	for (i = 0; i < s; i++) {
		printf("%d ", c[i]);
	}
}
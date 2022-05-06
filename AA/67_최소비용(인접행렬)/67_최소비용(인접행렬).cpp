#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, map[21][21], ch[21], cost = 2147000000;

void DFS(int v, int sum) {
	int i;
	if (v == n) {
		if (sum < cost) {
			cost = sum;
		}		
	}
	else {
		for (i = 1; i <= n; i++) {
			if (map[v][i] != 0 && ch[i] == 0) {				
				ch[i] = 1;
				DFS(i, sum + map[v][i]);
				ch[i] = 0;
			}
		}
	}
}

int main() {
	int i, a, b, c;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = c;
	}

	ch[1] = 1;
	DFS(1, 0);
	printf("%d\n", cost);
}
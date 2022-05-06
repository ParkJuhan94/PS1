#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void DFS(int x) {
	if (x == 0) return;
	else {
		DFS(x - 1);
		printf("%d ", x);
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	scanf("%d", &n);
	DFS(n);
	return 0;
}
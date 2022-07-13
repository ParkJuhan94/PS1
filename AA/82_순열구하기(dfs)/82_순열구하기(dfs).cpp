#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, r, cnt = 0;
int a[20], res[20], ch[20];
//	res는 출력할 숫자를 담는 tmp배열

void DFS(int L) {
	if (L == r) {
		for (int j = 0; j < L; j++) {
			printf("%d ", res[j]);
		}
		cnt++;
		puts("");
	}
	else {
		//	n가지의 모든 경우를 탐색 -> 이미 쓰인 숫자면 안씀, 안쓰인 숫자면 res에 넣고, 체크 걸고, DFS(L+1) 호출
		for (int i = 1; i <= n; i++) {
			if (ch[i] == 0) {
				res[L] = a[i];
				ch[i] = 1;
				DFS(L + 1);
				ch[i] = 0;
			}
		}
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &r);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	DFS(0);
	printf("%d\n", cnt);
	return 0;
}
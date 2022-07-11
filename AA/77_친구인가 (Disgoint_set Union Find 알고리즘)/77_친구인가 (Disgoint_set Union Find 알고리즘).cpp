#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//	각 index는 사람의 번호이고, 메모리에는 해당 그룹의 부모의 index가 있음.(루트 아님!!! 부모임)
int unf[1001];

//	v가 속하는 트리 그룹의 루트를 반환
int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);		//	재귀로 경로 압축 (가지가 1개이던 것을 여러 개의 가지로 묶어서, 레벨을 낮춤)
}

//	a와 b를 같은 트리 집합으로 합침
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;		//	서로 다른 집합이면 같은 집합으로 합쳐라
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int i, n, m, a, b, fa, fb, j;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		unf[i] = i;
	}

	for (i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		Union(a, b);
	}

	scanf("%d %d", &a, &b);
	fa = Find(a);
	fb = Find(b);
	if (fa == fb) printf("YES\n");	//	각 트리의 루트가 같으면 -> 같은 집합
	else printf("NO\n");

	return 0;
}
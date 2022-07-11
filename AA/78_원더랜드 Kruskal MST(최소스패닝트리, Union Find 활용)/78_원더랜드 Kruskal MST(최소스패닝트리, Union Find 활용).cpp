#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int unf[10001];

struct Edge {
	int s;	
	int e;
	int val;
	Edge(int a, int b, int c) {
		s = a;
		e = b;
		val = c;
	}
	//	거리비용 val을 기준으로 오름차순 정렬 후 탐색 -> 최소비용 문제니까
	bool operator<(const Edge& b)const {
		return val < b.val;		
	}
};

int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	vector<Edge> Ed;
	int i, n, m, a, b, c, cnt = 0, res = 0;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		unf[i] = i;
	}

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));
	} 
	sort(Ed.begin(), Ed.end());

	for (i = 0; i < m; i++) {
		int fa = Find(Ed[i].s);
		int fb = Find(Ed[i].e);
		if (fa != fb) {
			res += Ed[i].val;
			Union(Ed[i].s, Ed[i].e);
		}
	}

	printf("%d\n", res);
	return 0;
}
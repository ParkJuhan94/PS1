#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int ch[30];
struct Edge {
	int e;
	int val; 
	Edge(int a, int b) {
		e = a;
		val = b;
	}

	//	최소힙으로 만들려고 val > b.val;
	bool operator<(const Edge& b)const {
		return val > b.val;
	}
};

int main() {
	//freopen("input.txt", "rt", stdin);
	priority_queue<Edge> Q;
	vector<pair<int, int> > map[30];	//가중치를 포함한 인접리스트
	int i, n, m, a, b, c, res = 0;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));	//무방향이라서 a & b 각각 push_back
		map[b].push_back(make_pair(a, c));
	}
	
	//	시작점을 임의로 1로 잡았고, 가중치는 0으로 잡아서 push
	//	while의 로직을 돌리기 위해서 시작점을 큐에 넣어줘야만한다 -> 초깃값 조작하기!!!
	Q.push(Edge(1, 0));		
	while (!Q.empty()) {
		Edge tmp = Q.top();		//가중치가 최소인 간선을 방문
		Q.pop();
		int v = tmp.e;
		int cost = tmp.val;
		if (ch[v] == 0) {
			res += cost;
			ch[v] = 1;
			//연결된 노드 방문하면서 첫방문이면 큐에 push
			for (i = 0; i < map[v].size(); i++) {
				if (ch[map[v][i].first] == 0) {
					Q.push(Edge(map[v][i].first, map[v][i].second));
				}
			}
		}

	}
	printf("%d\n", res);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int vex;
	int dis;
	Edge(int a, int b) {
		vex = a;
		dis = b;
	}
	//	이 Edge를 priority_queue에 넣으면 최소힙이 됨(최대힙에서 부호가 반대이니까)
	bool operator<(const Edge& b)const {
		return dis > b.dis;
	}
};

int main() {
	priority_queue<Edge> Q;
	vector<pair<int, int>> graph[30];
	int i, n, m, a, b, c;

	scanf("%d %d", &n, &m);
	vector<int> dist(n + 1, 2147000000);	//	무한대로 초기화

	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));		
	}

	//	while을 돌리기 위한 초기 셋팅!!!!!!
	Q.push(Edge(1, 0));
	dist[1] = 0;

	while (!Q.empty()) {
		//	Q의 top에는 안에 있는 Edge 중에서 최소의 dis를 가진 Edge가 있음.
		int now = Q.top().vex;
		int cost = Q.top().dis;
		Q.pop();		

		//	top에 있는 Edge의 dis가 최소이긴한데, dist 배열의 값보다 커서 갱신이 안될 때
		if (cost > dist[now]) continue;		

		//	인접 노드 탐색
		for (i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextDis = cost + graph[now][i].second;

			//	거리가 더 작으면 갱신하는 부분
			if (dist[next] > nextDis) {
				dist[next] = nextDis;
				Q.push(Edge(next, nextDis));
			}
		}
	}

	//	기존의 무한대 2147000000이 갱신이 안되어있으면 impossible로 처리
	for (i = 2; i <= n; i++) {
		if (dist[i] != 2147000000) printf("%d : %d\n", i, dist[i]);
		else printf("%d : impossible\n", i);
	}
}
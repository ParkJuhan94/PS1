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
	//	�� Edge�� priority_queue�� ������ �ּ����� ��(�ִ������� ��ȣ�� �ݴ��̴ϱ�)
	bool operator<(const Edge& b)const {
		return dis > b.dis;
	}
};

int main() {
	priority_queue<Edge> Q;
	vector<pair<int, int>> graph[30];
	int i, n, m, a, b, c;

	scanf("%d %d", &n, &m);
	vector<int> dist(n + 1, 2147000000);	//	���Ѵ�� �ʱ�ȭ

	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));		
	}

	//	while�� ������ ���� �ʱ� ����!!!!!!
	Q.push(Edge(1, 0));
	dist[1] = 0;

	while (!Q.empty()) {
		//	Q�� top���� �ȿ� �ִ� Edge �߿��� �ּ��� dis�� ���� Edge�� ����.
		int now = Q.top().vex;
		int cost = Q.top().dis;
		Q.pop();		

		//	top�� �ִ� Edge�� dis�� �ּ��̱��ѵ�, dist �迭�� ������ Ŀ�� ������ �ȵ� ��
		if (cost > dist[now]) continue;		

		//	���� ��� Ž��
		for (i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextDis = cost + graph[now][i].second;

			//	�Ÿ��� �� ������ �����ϴ� �κ�
			if (dist[next] > nextDis) {
				dist[next] = nextDis;
				Q.push(Edge(next, nextDis));
			}
		}
	}

	//	������ ���Ѵ� 2147000000�� ������ �ȵǾ������� impossible�� ó��
	for (i = 2; i <= n; i++) {
		if (dist[i] != 2147000000) printf("%d : %d\n", i, dist[i]);
		else printf("%d : impossible\n", i);
	}
}
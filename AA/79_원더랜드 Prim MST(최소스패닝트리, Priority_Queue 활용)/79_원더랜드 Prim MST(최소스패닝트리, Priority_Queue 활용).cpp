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

	//	�ּ������� ������� val > b.val;
	bool operator<(const Edge& b)const {
		return val > b.val;
	}
};

int main() {
	//freopen("input.txt", "rt", stdin);
	priority_queue<Edge> Q;
	vector<pair<int, int> > map[30];	//����ġ�� ������ ��������Ʈ
	int i, n, m, a, b, c, res = 0;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));	//�������̶� a & b ���� push_back
		map[b].push_back(make_pair(a, c));
	}
	
	//	�������� ���Ƿ� 1�� ��Ұ�, ����ġ�� 0���� ��Ƽ� push
	//	while�� ������ ������ ���ؼ� �������� ť�� �־���߸��Ѵ� -> �ʱ갪 �����ϱ�!!!
	Q.push(Edge(1, 0));		
	while (!Q.empty()) {
		Edge tmp = Q.top();		//����ġ�� �ּ��� ������ �湮
		Q.pop();
		int v = tmp.e;
		int cost = tmp.val;
		if (ch[v] == 0) {
			res += cost;
			ch[v] = 1;
			//����� ��� �湮�ϸ鼭 ù�湮�̸� ť�� push
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
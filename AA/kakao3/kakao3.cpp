#include <stdio.h>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#define x first
#define y second
using namespace std;

int ch[101], cnt = 0, n, cost = 2147000000;
int maxAlp, maxCop = 0;
vector<pair<int, int> > map[101];

void DFS(int v, int sum, int alp, int cop) {
	int i;
	if (v == n) {
		if (alp >= maxAlp && cop >= maxCop) {
			if (sum < cost) cost = sum;
		}
	}
	else {
		for (i = 0; i < map[v].size(); i++) {
			if (ch[map[v][i].x] == 0) {
				
				DFS(map[v][i].x, sum + v, map[v][i].x, map[v][i].y);
				
			}
		}
	}
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int i, j;
	n = problems.size();

    for (i = 1; i <= problems.size(); i++) {
		if (problems[i][2] > maxAlp) {
			maxAlp = problems[i][2];
		}
		if (problems[i][3] > maxCop) {
			maxCop = problems[i][3];
		}
		map[problems[i][4]].push_back(make_pair(problems[i][0], problems[i][1]));
    }
	
	DFS(1, 0, alp, cop);

	answer = cost;

    return answer;
}
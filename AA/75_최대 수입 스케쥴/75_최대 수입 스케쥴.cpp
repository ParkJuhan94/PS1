#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Data {
	int money;
	int when;
	Data(int a, int b) {
		money = a;
		when = b;
	}
	bool operator<(const Data& b)const {
		return when > b.when;
	}
};
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, i, j, a, b, res = 0, max = -2147000000;
	vector<Data> T;
	priority_queue<int> pQ;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		T.push_back(Data(a, b));

		//	가장 뒤의 마감 기간 찾기
		if (b > max)
			max = b;
	}

	sort(T.begin(), T.end());

	j = 0;
	for (i = max; i >= 1; i--) {
		for (; j < n; j++) {
			if (T[j].when < i) break;
			pQ.push(T[j].money);
		}
		if (!pQ.empty()) {
			res += pQ.top();
			pQ.pop();
		}
	}
	printf("%d\n", res);
	return 0;
}
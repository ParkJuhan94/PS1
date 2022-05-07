#include <stdio.h>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int total = 0, cnt = 0, p1 = 0, p2 = 0, ch[4];
int answer = 0, i, part = 0, x, pos;
queue<int> q1, q2, q3, tmpQ1, tmpQ2;

int solution(vector<int> queue1, vector<int> queue2) {

	for (i = 0; i < queue1.size(); i++) {
		total += queue1[i];
		total += queue2[i];
		part += queue1[i];
		q1.push(queue1[i]);
		q2.push(queue2[i]);
	}		

	q3.push(1);
	q3.push(2);
	q3.push(3);	

	while (!q3.empty()) {
		x = q3.front();
		q3.pop();
		tmpQ1 = q1;
		tmpQ2 = q2;

		if (x == 1) {
			q2.push(q1.front());
			part -= q1.front();
			q1.pop();

			q3.push(1); q3.push(2); q3.push(3);
			cnt++;

			if (part * 2 == total) answer = cnt;
		}
		else if (x == 2) {
			q1.push(q2.front());
			part -= q2.front();
			q2.pop();

			q3.push(1); q3.push(2); q3.push(3);
			cnt++;

			if (part * 2 == total) answer = cnt;
		}
		else if (x == 3) {
			q2.push(q1.front());
			q1.push(q2.front());
			part -= q1.front();
			part += q2.front();
			q1.pop();
			q2.pop();

			q3.push(1); q3.push(2); q3.push(3);
			cnt++;

			if (part * 2 == total) answer = cnt;
		}

		for (i = 1; i <= 3; i++) {			

			if (x == 1) {
				q2.push(q1.front());
				part -= q1.front();
				q1.pop();

				q3.push(1); q3.push(2); q3.push(3);
				cnt++;

				if (part * 2 == total) answer = cnt;
			}
			else if (x == 2) {
				q1.push(q2.front());
				part -= q2.front();
				q2.pop();

				q3.push(1); q3.push(2); q3.push(3);
				cnt++;

				if (part * 2 == total) answer = cnt;
			}
			else if (x == 3) {
				q2.push(q1.front());
				q1.push(q2.front());
				part -= q1.front();
				part += q2.front();
				q1.pop();
				q2.pop();

				q3.push(1); q3.push(2); q3.push(3);
				cnt++;

				if (part * 2 == total) answer = cnt;
			}
		}

		



	}
	
	if (answer == 0) {
		answer = -1;
	}	
    return answer;
}

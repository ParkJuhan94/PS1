#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <stdlib.h>
#include <map>
#include <unordered_map>
using namespace std;

int Answer;

struct ant {
	int p, v;
	ant(int p, int v) {
		this->p = p;
		this->v = v;
	}
	bool operator < (const ant& a)const {
		if (v != a.v) return v < a.v;
		if (p != a.p) return p < a.p;
	}
};

int main(int argc, char** argv)
{
	int T, test_case;	

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		setbuf(stdout, NULL);
		int n, i, j, pa, va, vMid, pos = 0, start = 0;
		int *p, *v;				
		unordered_map<int, int> m;
		//vector<pair<int, int>> vp;
		vector<ant> a;	
		vector<ant> b;

		Answer = 0;

		scanf("%d", &n);
		p = (int*)malloc(sizeof(int) * n);
		v = (int*)malloc(sizeof(int) * n);	
		
		for (i = 0; i < n; i++) {
			scanf("%d", &p[i]);
		}		
		for (i = 0; i < n; i++) {
			scanf("%d", &v[i]);			
			a.push_back(ant(p[i], v[i]));			
		}				
		b = a;
		sort(b.begin(), b.end());
		for (i = 0; i < n; i++) {						
			m.insert({ b[i].p, i });			
		}

//		for (auto i : m) printf("map : %d %d\n", i.first, i.second);

		for (i = 0; i < n; i++) {				
			Answer += abs(a[i].p - a[m[a[i].p]].p);				
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
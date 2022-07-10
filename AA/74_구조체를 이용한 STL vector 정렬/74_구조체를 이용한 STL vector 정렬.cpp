#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Loc {
	int x, y, z;

	Loc(int a, int b, int c) {
		x = a;
		y = b;
		z = c;
	}

	/*
	* x->y->z 순으로 오름차순 정렬하기 위함. sort에서 쓰인다.
	
	2 3 1
	2 3 5
	3 1 6
	3 6 7
	5 2 3

	*/
	bool operator < (const Loc& b) const {
		if (x != b.x) return x < b.x;
		if (y != b.y) return y < b.y;
		if (z != b.z) return z < b.z;
	}
};

int main() {
	vector<Loc> XY;
	XY.push_back(Loc(2, 3, 5));
	XY.push_back(Loc(3, 6, 7));
	XY.push_back(Loc(2, 3, 1));
	XY.push_back(Loc(5, 2, 3));
	XY.push_back(Loc(3, 1, 6));
	sort(XY.begin(), XY.end());
	for (auto pos : XY) cout << pos.x << " " << pos.y << " " << pos.z << endl;
}
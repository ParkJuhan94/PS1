#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;

int solution(int price, int money, int count) {
	int i, sum = 0;

	for (i = 1; i <= count; i++) {
		sum += price * i;
	}
	
	if (sum <= money) {
		return 0;
	}
	else {
		return sum - money;
	}
}

int main() {
	printf("%d\n", solution(3, 20, 4));
}
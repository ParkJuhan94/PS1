#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include<iostream>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	stack<char> s;
	char a[50];
	int i;
	
	scanf("%s", &a);

	for (i = 0; a[i] != 0; i++) {
		if (a[i] == '(') s.push(a[i]);
		else {
			if (s.empty()) {
				printf("NO\n");				
				return 0;
			}
			else {
				s.pop();
			}
		}
	}
	if (s.empty()) printf("YES\n");
	else printf("NO\n");

	return 0;
}
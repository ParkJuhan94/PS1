#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main() {
	freopen("input.txt", "rt", stdin);
	int a, b, sum = 0, i;
	cin >> a >> b;
	for (i = a; i < b; i++) {
		sum += i;
		printf("%d + ", i);
	}
	printf("%d = %d\n", i, sum + i);
	
	return 0;
}
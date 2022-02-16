#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

int main() {
	int numStu, sum = 0;
	int a[10] = { 0 };
	int answer[10] = { 0 };
	int i,j;

	scanf("%d", &numStu);

	for (i = 0; i < numStu; i++) {
		scanf("%d %d", &a[i], &answer[i]);
	}

	for (i = 0; i < numStu; i++) {
		sum = 0;
		for (j = 1; j <= a[i]; j++) {
			sum += j;
		}
		if (sum == answer[i]) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	//	위의 두 반복문을 하나의 반복문으로 합치고 -> a[], answer[] 을 배열 말고 일반 변수로 가능
}
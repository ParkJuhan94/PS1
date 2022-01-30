#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

int cnt[50001];		//	전역변수로 잡으면 자동으로 0으로 초기화됨

//	타임리밋을 고려하여 시간복잡도를 n*logn 이하로 잡아야함
//	1부터 n까지 돌면서 자신의 배수에 카운팅을 해주는 알고리즘(이때 j += i 로 증가해야함)
int main() {
	int n, i, j;	

	scanf("%d", &n);
	
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j += i) {	//i가 3일때 cnt[3],cnt[6],cnt[9],,,에 ++
			cnt[j]++;
		}
	}

	for (i = 1; i <= n; i++) {
		printf("%d ", cnt[i]);
	}
}



/*
	시간복잡도가 n^2 이라서 n이 30000을 넘어가면 1초 이상걸림. 타임 에러

int main(){
	int n, i, j;
	int cnt = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		cnt = 0;	
		for (j = 1; j <= i; j++) {
			if (i % j == 0) cnt++;			
		}
		printf("%d ", cnt);
	}
}

*/


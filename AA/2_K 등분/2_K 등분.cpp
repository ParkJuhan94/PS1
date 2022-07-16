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

int combination(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	else
		return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main(int argc, char** argv)
{
	int T, test_case;	

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int i, j, N, k, cnt = 0;
		
		int val;
		long long int ret;		
		
		Answer = 0;

		scanf("%d %d", &N, &k);		
		int* sum = new int[N+1]();
		int* inp = new int[N+1]();
		long long int* dp = new long long int[N+1]();		

		for (i = 1; i <= N; i++) 
		{
			scanf("%d", &inp[i]);
			sum[i] = sum[i - 1] + inp[i];						
		}
		
		// 나올 수 없는 경우
		if (sum[N] % k > 0) ret = 0;
		else {
			// 누적합이 0인 경우
			if (!sum[N]) {
				long long int zero = 0;
				for (i = 1; i <= N; i++) zero += (!sum[i]);

				vector<bool> temp(zero-1, false);
				for (int i = 0; i < k-1; i++) // 앞부터 r개의 true가 채워진다. 나머지 뒤는 false.
					temp[i] = true;

				do {
					for (int i = 0; i < zero-1; ++i) {
						if (temp[i])
							cnt++;
					}
					cout << endl;
				} while (prev_permutation(temp.begin(), temp.end()));
				ret = cnt;
			}

			// DP
			else {
				dp[0] = 1;
				val = sum[N] / k;				

				for (i = 1; i <= N; i++) {
					int t = sum[i] / val;
					if (sum[i] % val != 0 or t < 1 or t>k) continue;
					
					dp[t] += dp[t - 1];
					//printf("dp[%d] = %d\n", t, dp[t]);
				}

				ret = dp[k-1];
			}
		}

		Answer = ret;														
		Answer %= 1000000007;
		std::cout << "Case #" << test_case + 1 << endl;
		std::cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
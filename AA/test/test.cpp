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
int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };



int solution(vector <vector<int>> masks, vector<string> dates) {
	int answer = 0;
	int i, j, lenYear, lenMonth = 0, lenDay, start, end, cnt = 0, flag = 0;
	vector<int> day(3650);
	vector<double> dayMask(masks.size());

	for (i = 0; i < masks.size(); i++) {
		dayMask[i] = masks[i][0] / masks[i][1];
	}

	sort(dates.begin(), dates.end());

	for (i = 0; i < dates.size(); i++) {
		if (dates[i].length() == 10) {
			lenYear = (stoi(dates[i].substr(0, 4)) - 2021) * 365;
			lenMonth = 0;
			for (j = 1; j < stoi(dates[i].substr(5, 2)); j++) {
				lenMonth += month[j];
			}			
			lenDay = stoi(dates[i].substr(8, 2));
			
			day[lenYear + lenMonth + lenDay] = 1;			
		}
		else {			
			lenYear = (stoi(dates[i].substr(0, 4)) - 2021) * 365;
			lenMonth = 0;
			for (j = 1; j < stoi(dates[i].substr(5, 2)); j++) {
				lenMonth += month[j];
			}
			lenDay = stoi(dates[i].substr(8, 2));
			start = lenYear + lenMonth + lenDay;

			lenYear = (stoi(dates[i].substr(11, 4)) - 2021) * 365;
			lenMonth = 0;
			for (j = 1; j < stoi(dates[i].substr(16, 2)); j++) {
				lenMonth += month[j];
			}
			lenDay = stoi(dates[i].substr(19, 2));
			end = lenYear + lenMonth + lenDay;

			for (j = start; j <= end; j++) {
				day[j] = 1;
			}
		}
	}

	for (i = 0; i < 3650; i++) {
		if (day[i] == 1) {
			flag = 1;
			cnt++;
		}
		else {
			if (flag == 1) {
				
			}
			cnt = 0;
		}
	}
	



	return answer;
}

int main() {
	vector <vector<int>> m = { {3200, 4} ,{2300, 2},{1100, 1},{4200, 6} };
	vector<string> d = { "2022/05/02", "2022/05/01", "2022/05/07", "2022/05/05", "2022/05/08",
		"2022/05/13~2022/05/15", "2022/05/14~2022/05/17", "2022/05/01~2022/05/02", "2022/05/16" };

	printf("%d\n", solution(m, d));
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//	�� index�� ����� ��ȣ�̰�, �޸𸮿��� �ش� �׷��� �θ��� index�� ����.(��Ʈ �ƴ�!!! �θ���)
int unf[1001];

//	v�� ���ϴ� Ʈ�� �׷��� ��Ʈ�� ��ȯ
int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);		//	��ͷ� ��� ���� (������ 1���̴� ���� ���� ���� ������ ���, ������ ����)
}

//	a�� b�� ���� Ʈ�� �������� ��ħ
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;		//	���� �ٸ� �����̸� ���� �������� ���Ķ�
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int i, n, m, a, b, fa, fb, j;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		unf[i] = i;
	}

	for (i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		Union(a, b);
	}

	scanf("%d %d", &a, &b);
	fa = Find(a);
	fb = Find(b);
	if (fa == fb) printf("YES\n");	//	�� Ʈ���� ��Ʈ�� ������ -> ���� ����
	else printf("NO\n");

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main() {
	//read
	int n;
	scanf("%d", &n);
	vector<set<int>> vec(n + 1);
 
	//read and build
	for (int i = 1; i <= n; ++i) {
		int m;
		scanf("%d", &m);
		while (m--) {
			int a;
			scanf("%d", &a);
			vec[i].insert(a);
		}
	}
 
	//solve
	int m;
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		set<int> sset;
		int nt = vec[a].size(), nc = 0;
		for (auto it = vec[b].begin(); it != vec[b].end(); ++it) {
			if (vec[a].find(*it) != vec[a].end()) {
				nc++;
			}
			else
				nt++;
		}
		printf("%.1f%%\n", nc*1.0 / nt * 100);
	}
 
	system("pause");
	return 0;
}

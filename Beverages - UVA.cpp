#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;

//=============================================================================================
const double pi = 3.14159265359;
#define p(a) ((a) * (a))
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
//=============================================================================================

int n, e;
vector<string> drinksName;

void topoSort(map<string, int> &drinks, vector<int> &inD, vector<vector<int> > &g) {
	priority_queue<int, vector<int>, greater<int> > zero;

	for (int i = 0; i < n; ++i) {
		if (!inD[i]) {
			zero.push(i);
		}
	}

	while (!zero.empty()) {
		int u = zero.top();
		zero.pop();
		cout << " " << drinksName[u];
		vector<int>::iterator it;

		for (it = g[u].begin(); it != g[u].end(); ++it) {
			--inD[*it];

			if (!inD[*it]) {
				zero.push(*it);
			}
		}
	}
}

int main() {
	int tc = 1;
	string u, v;

	while (scanf("%d", &n) == 1) {
		drinksName.clear();
		map<string, int> drinks;
		vector<vector<int> > g(n, vector<int>());
		vector<int> inD(n, 0);

		for (int i = 0; i < n; ++i) {
			cin >> u;
			drinks[u] = i;
			drinksName.push_back(u);
		}

		cin >> e;
		for (int i = 0; i < e; ++i) {
			cin >> u >> v;
			g[drinks[u]].push_back(drinks[v]);
			++inD[drinks[v]];
		}

		cout << "Case #" << tc++ << ":" << " Dilbert should drink beverages in this order:";
		topoSort(drinks, inD, g);
		puts(".\n");
	}
	return 0;
}

//#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <fstream>
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
vector<string> names;
vector<vector<int>> g(26, vector<int>());
vector<int> res;
bool vs[26], path[26];

bool dfs(int u) {
	vs[u] = path[u] = true;

	for (int i = 0; i < g[u].size(); ++i) {
		if (path[g[u][i]]) {
			puts("Impossible");
			exit(0);
		}
		else if (!vs[g[u][i]]) {
			dfs(g[u][i]);
		}
	}

	path[u] = false;
	res.push_back(u);
}

inline void checkViolations(int &id) {
	for (int i = 0; i < names[id].length() && i < names[id + 1].length(); ++i) {
		if (names[id][i] != names[id + 1][i]) {
			g[names[id + 1][i] - 'a'].push_back(names[id][i] - 'a');
			return;
		}
	}

	if (names[id].length() > names[id + 1].length()) {
		puts("Impossible");
		exit(0);
	}
}

int main() {
	cin >> n;
	names.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> names[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		checkViolations(i);
	}

	for (int i = 0; i < 26; ++i) {
		if (!vs[i]) {
			dfs(i);
		}
	}

	for (int i = 0; i < 26; ++i) {
		putchar(res[i] + 'a');
	}

	return 0;
}
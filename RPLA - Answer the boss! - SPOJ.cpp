#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <iomanip>
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

int n, e, pos;

inline void topologicalSort(vector<vector<int>> &g, vector<int> &res, vector<int> &inD) {
	priority_queue <int, vector<int>, greater<int>> zero;

	for (int i = 0; i < n; ++i) {
		if (!inD[i]) {
			zero.push(i);
		}
	}

	while (!zero.empty()) {
		int u = zero.top();
		zero.pop();
		res.push_back(u);
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
	ios_base::sync_with_stdio(false);

	int tc, scenario = 1;
	cin >> tc;

	while (tc--) {
		cin >> n >> e;

		vector<vector<int>> g(n, vector<int>());
		vector<int> res;
		vector<int> inD(n, 0);

		for (int u, v, i = 0; i < e; ++i) {
			cin >> v >> u;
			g[u].push_back(v);
			++inD[v];
		}

		vector<int> rank(n, 1);
		vector<pii> ans;

		topologicalSort(g, res, inD);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < g[res[i]].size(); ++j) {
				int v = g[res[i]][j];
				rank[v] = max(rank[v], rank[res[i]] + 1);
			}

			ans.push_back({ rank[res[i]], res[i] });
		}
		sort(ans.begin(), ans.end());

		cout << "Scenario #" << scenario++ << ":" << endl;
		for (auto i : ans) {
			cout << i.first << " " << i.second << endl;
		}
		cout << endl;
	}

	return 0;
}

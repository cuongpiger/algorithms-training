#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
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

//https://www.spoj.com/problems/TOPOSORT/

int n, m;
 
bool topologicalSort(vector<vector<int>> &grp, vector<int> &res) {
	vector<int> inDegree(n + 1, 0);
	priority_queue <int, vector<int>, greater<int> > zeroInDegree;
 
	for (int u = 1; u <= n; ++u) {
		vector<int>::iterator it;
 
		for (it = grp[u].begin(); it != grp[u].end(); ++it) {
			++inDegree[*it];
		}
	}
 
	for (int i = 1; i <= n; ++i) {
		if (!inDegree[i]) {
			zeroInDegree.push(i);
		}
	}
 
	while (!zeroInDegree.empty()) {
		int u = zeroInDegree.top();
		zeroInDegree.pop();
		res.push_back(u);
		vector<int>::iterator it;
 
		for (it = grp[u].begin(); it != grp[u].end(); ++it) {
			--inDegree[*it];
 
			if (!inDegree[*it]) {
				zeroInDegree.push(*it);
			}
		}
	}
 
	for (int i = 1; i <= n; ++i) {
		if (inDegree[i]) {
			return false;
		}
	}
 
	return true;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
 
	vector<vector<int>> grp;
	vector<int> res;
 
	cin >> n >> m;
	grp.assign(n + 1, vector<int>());
 
	for (int u, v, i = 0; i < m; ++i) {
		cin >> u >> v;
		grp[u].push_back(v);
	}
 
	if (topologicalSort(grp, res)) {
		for (int i = 0; i < res.size(); ++i) {
			cout << res[i] << " ";
		}
	}
	else {
		cout << "Sandro fails.";
	}
	cout << endl;
 
	return 0;
} 

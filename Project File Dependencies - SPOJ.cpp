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
#define pw(a) ((a) * (a))
#define x first
#define y second
const double pi = 3.14159265359;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
//=============================================================================================

//https://www.spoj.com/problems/PFDEP/
/**
** Comment **
**/

int n, m; // the number of N tasks and M rules
vector<vector<int>> grp;
vector<int> indegree;

void kahn(){
	priority_queue <int, vector<int>, greater<int>> zero_indegree;

	for (int i = 1; i <= n; ++i){
		if (!indegree[i]){
			zero_indegree.push(i);
		}
	}

	while (!zero_indegree.empty()){
		int u = zero_indegree.top();
		zero_indegree.pop();
		cout << u << " ";

		for (vector<int>::iterator it = grp[u].begin(); it != grp[u].end(); ++it){
			--indegree[*it];

			if (!indegree[*it]){
				zero_indegree.push(*it);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int k, u, v;

	cin >> n >> m;
	grp.resize(n + 1, vector<int>());
	indegree.resize(n + 1, 0);

	for (int i = 0; i < m; ++i){
		cin >> v >> k;

		for (int i = 0; i < k; ++i){
			cin >> u;
			grp[u].push_back(v);
			++indegree[v];
		}
	}
	kahn();

	return 0;
}

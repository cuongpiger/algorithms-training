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
#include <sstream>
using namespace std;

//=============================================================================================
#define pw(a) ((a) * (a))
#define _x first
#define _y second
#define vit vector<int>::iterator
#define _cin(X) int (X); cin >> X
const double pi = 3.14159265359;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
typedef vector<bool> vbool;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a %b); }
inline double _distance(const pii &a, const pii &b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=============================================================================================

/**
** Comment **
https://www.geeksforgeeks.org/topological-sorting-using-departure-time-of-vertex/
**/

int vertices;
vvint grp;
vbool vs;
vint departure;
vint arrive;

void dfs(int vertex, int &t) {
	vs[vertex] = true;
	arrive[vertex] = t++;

	for (auto neighbor : grp[vertex]) {
		if (!vs[neighbor]) dfs(neighbor, t);
	}
	departure[vertex] = t++;
}

inline void topologicalSort() {
	int t = 1;
	for (int i = 1; i <= vertices; ++i) {
		if (!vs[i]) dfs(i, t);
	}
}
																					
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int queries, oliver, bob, type;
	cin >> vertices;
	grp.resize(vertices + 1, vint());
	vs.resize(vertices + 1, false);
	departure.resize(vertices + 1, -1);
	arrive.resize(vertices + 1, -1);

	for (int u, v, i = 0; i < vertices - 1; ++i) {
		cin >> u >> v;
		grp[u].push_back(v);
		grp[v].push_back(u);
	}

	topologicalSort();
	cin >> queries;
	while (queries--) {
		cin >> type >> oliver >> bob;
		if (!type) swap(oliver, bob);
		
		if (departure[oliver] <= departure[bob] && arrive[bob] <= arrive[oliver]) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
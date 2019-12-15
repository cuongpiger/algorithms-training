#pragma warning(disable:4996)
#include <iostream>
#include <cstdint>
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
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pw(a) ((a) * (a))
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define dqit deque<int>::iterator
#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define sortRev greater<int>()
const double pi = 3.14159265359;
const long long mod = 1e9 + 7;
typedef uint64_t uit;
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<double, int> pdi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
typedef pair<ll, string> plls;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pdi> vpdi;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<long long>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<vector<int>>> vvvi;
typedef deque<int> dqi;
typedef queue<int> qi;
typedef queue<pii> qpii;
int GCD(int a, int b) { return !b ? a : GCD(b, a % b); }
inline double DIST(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
inline int DEC(char x) { return (int)(x - '0'); }
/*__________________________________________________________________________________________________________________________
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1498
____________________________________________________________________________________________________________________________*/

const int INF = -1e9;
int n;
int energy[105];
vi grp[105];

inline bool bfs(int src) {
	vb vs(n + 5, false);
	vs[src] = true;
	qi q;
	q.push(src);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (u == n) {
			return true;
		}

		for (int i = 0; i < grp[u].size(); ++i) {
			int v = grp[u][i];

			if (!vs[v]) {
				vs[v] = true;
				q.push(v);
			}
		}
	}

	return false;
}

inline bool bellmanFord() {
	vi dist(n + 5, INF);
	dist[1] = 100;

	for (int k = 1; k < n; ++k) {
		for (int i = 1; i <= n; ++i) {
			if (dist[i] <= 0) {
				continue;
			}

			for (int j = 0; j < grp[i].size(); ++j) {
				if (dist[grp[i][j]] < dist[i] + energy[grp[i][j]]) {
					dist[grp[i][j]] = dist[i] + energy[grp[i][j]];
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (dist[i] <= 0) {
			continue;
		}

		for (int j = 0; j < grp[i].size(); ++j) {
			if (dist[grp[i][j]] < dist[i] + energy[grp[i][j]] && bfs(i)) {
				return true;
			}
		}
	}

	return dist[n] > 0;
}

int main() {
	FAST_IO;
	//FILE_IO;

	while (cin >> n && n != -1) {
		for (int noEdge, edge, i = 1; i <= n; ++i) {
			cin >> energy[i] >> noEdge;
			grp[i].clear();

			while (noEdge--) {
				cin >> edge;
				grp[i].push_back(edge);
			}
		}

		if (bellmanFord()) {
			cout << "winnable" << endl;
		}
		else {
			cout << "hopeless" << endl;
		}
	}

	return 0;
}
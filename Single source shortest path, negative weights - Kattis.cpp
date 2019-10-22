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
https://open.kattis.com/submissions/4820704
____________________________________________________________________________________________________________________________*/

const int INF = 1e9;
typedef struct Node {
	int source;
	int target;
	int weight;

	Node(int _src, int _des, int _wgt) {
		source = _src;
		target = _des;
		weight = _wgt;
	}
} Node;

int n, m, q, s;
vector<Node> grp;

inline void bellmanFord(int src, vi &dist) {
	dist.resize(n + 5, INF);
	dist[src] = 0;

	for (int i = 1; i < n; ++i) {
		for (int u, v, w, j = 0; j < m; ++j) {
			u = grp[j].source;
			v = grp[j].target;
			w = grp[j].weight;

			if (dist[u] != INF && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
			}
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int u, v, w, j = 0; j < m; ++j) {
			u = grp[j].source;
			v = grp[j].target;
			w = grp[j].weight;

			if (dist[u] != INF && dist[v] > dist[u] + w) {
				dist[v] = -INF;
			}
		}
	}
}

int main() {
	FAST_IO;
	//FILE_IO;

	while (cin >> n >> m >> q >> s && n + m + q + s != 0) {
		for (int u, v, w, i = 0; i < m; ++i) {
			cin >> u >> v >> w;
			grp.push_back(Node(u, v, w));
		}

		vi dist;
		bellmanFord(s, dist);

		while (q--) {
			cin >> m;

			if (dist[m] == INF) {
				cout << "Impossible" << endl;
			}
			else if (dist[m] == -INF) {
				cout << "-Infinity" << endl;
			}
			else {
				cout << dist[m] << endl;
			}
		}

		cout << endl;
		grp.clear();
	}

	return 0;
}
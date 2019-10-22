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
http://www.lightoj.com/volume_showproblem.php?problem=1074
____________________________________________________________________________________________________________________________*/

const int INF = 1e9;
typedef struct Node {
	int src;
	int des;
	int wgt;

	Node(int _src, int _des, int _wgt) {
		src = _src;
		des = _des;
		wgt = _wgt;
	}
} Node;

int V, E;
int weight[205];
vector<Node> grp;

inline int calcDist(int u, int v) {
	return pow(weight[v] - weight[u], 3.0);
}

inline void BellMan_Ford(int source, vi &dist) {
	dist.resize(V + 5, INF);
	dist[source] = 0;

	for (int i = 1; i < V; ++i) {
		for (int j = 0; j < E; ++j) {
			int u = grp[j].src;
			int v = grp[j].des;
			int w = grp[j].wgt;

			if (dist[u] != INF && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
			}
		}
	}
}

int main() {
	FAST_IO;
	//FILE_IO;

	int tc, cs = 1;
	cin >> tc;

	while (tc--) {
		cin >> V;
		for (int i = 1; i <= V; ++i) {
			cin >> weight[i];
		}

		cin >> E;
		for (int u, v, i = 0; i < E; ++i) {
			cin >> u >> v;
			grp.push_back(Node(u, v, calcDist(u, v)));
		}

		vector<int> dist;
		BellMan_Ford(1, dist);

		int q, v;
		cin >> q;

		cout << "Case " << cs++ << ":" << endl;
		while (q--) {
			cin >> v;

			if (dist[v] != INF && dist[v] >= 3) {
				cout << dist[v] << endl;
			}
			else {
				cout << "?" << endl;
			}
		}

		grp.clear();
	}

	return 0;
}
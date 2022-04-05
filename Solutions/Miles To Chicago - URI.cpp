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
https://www.urionlinejudge.com.br/judge/en/problems/view/1655
____________________________________________________________________________________________________________________________*/

typedef struct Node {
	int u, v;
	double w;

	Node(int _u, int _v, double _w) {
		u = _u;
		v = _v;
		w = _w;
	}
} Node;

int main() {
	FAST_IO;
	//FILE_IO;
	int V, E;

	while (cin >> V && V) {
		cin >> E;
		int u, v;
		double w;
		vector<Node> grp;
		vector<double> dist(V + 5, -1);
		dist[1] = 1;

		for (int i = 0; i < E; ++i) {
			cin >> u >> v >> w;
			grp.push_back(Node(u, v, w/100.0));
		}

		for (int i = 0; i < V - 1; ++i) {
			for (int j = 0; j < grp.size(); ++j) {
				Node x = grp[j];
				dist[x.u] = max(dist[x.u], dist[x.v] * x.w);
				dist[x.v] = max(dist[x.v], dist[x.u] * x.w);
			}
		}

		cout << fixed << setprecision(6) << dist[V] * 100.0 << " percent" << endl;
	}

	return 0;
}
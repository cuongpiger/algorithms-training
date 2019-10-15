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
https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1594
____________________________________________________________________________________________________________________________*/
#define x first
#define y second
const int INF = 1e9;
const int X[] = { 0, -1, 0, 1 };
const int Y[] = { -1, 0, 1, 0 };

int m, n;
pii src, des;
bool grp[1005][1005];

inline bool canGo(pii p) {
	if (p.x < 0 || p.x >= m || p.y < 0 || p.y >= n || grp[p.x][p.y] == true) {
		return false;
	}

	return true;
}

inline int bfs() {
	vvi dist(m + 5, vi(n + 5, INF));
	qpii q;
	dist[src.x][src.y] = 0;
	q.push(pii(src.x, src.y));

	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		if (u.x == des.x && u.y == des.y) {
			break;
		}

		for (int i = 0; i < 4; ++i) {
			pii v = pii(u.x + X[i], u.y + Y[i]);

			if (canGo(v) && dist[v.x][v.y] == INF) {
				dist[v.x][v.y] = dist[u.x][u.y] + 1;
				q.push(v);
			}
		}
	}

	return dist[des.x][des.y];
}

int main() {
	FAST_IO;
	//FILE_IO;

	while (cin >> m >> n && m && n) {
		int k; cin >> k;

		while (k--) {
			int r, c, no; cin >> r >> no;

			while (no--) {
				cin >> c;
				grp[r][c] = true;
			}
		}

		cin >> src.x >> src.y;
		cin >> des.x >> des.y;
		cout << bfs() << endl;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				grp[i][j] = false;
			}
		}
	}

	return 0;
}
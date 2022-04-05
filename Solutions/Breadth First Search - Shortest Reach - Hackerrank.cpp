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

//=========================================================================================================================
#define pw(a) ((a) * (a))
#define vit vector<int>::iterator
#define dqit deque<int>::iterator
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
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
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pdi> vpdi;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<pii>> vvpii;
typedef deque<int> dqi;
typedef queue<int> qi;
int GCD(int a, int b) { return !b ? a : GCD(b, a % b); }
inline double DIST(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
inline int DEC(char x) { return (int)(x - '0'); }
//=========================================================================================================================

//https://www.hackerrank.com/challenges/bfsshortreach/problem?fbclid=IwAR3m6Vvg7EMb7PaAFlbBr_fL-f8hWaLx00xTV7iaie3lP16mDGP4YkAkRf4
/**
** Comment **
**/

inline void BFS(int s, vb& vs, vi& dist, vvi& grp) {
	qi q;
	vs[s] = true;
	q.push(s);
	dist[s] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < grp[u].size(); ++i) {
			int v = grp[u][i];

			if (!vs[v]) {
				vs[v] = true;
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	int tc; cin >> tc;

	while (tc--) {
		int V, E;
		cin >> V >> E;

		vb vs(V + 1, false);
		vi dist(V + 1, -1);
		vvi grp(V + 1);

		for (int u, v, i = 0; i < E; ++i) {
			cin >> u >> v;
			grp[u].push_back(v);
			grp[v].push_back(u);
		}

		int s; cin >> s;
		BFS(s, vs, dist, grp);

		for (int i = 1; i <= V; ++i) {
			if (i != s) {
				if (dist[i] != -1) {
					cout << dist[i] * 6 << " ";
				}
				else {
					cout << "-1 ";
				}
			}
		}

		cout << endl;
	}

	return 0;
}
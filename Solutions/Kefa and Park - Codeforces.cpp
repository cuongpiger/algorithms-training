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

//==========================================================================================================================
#define pw(a) ((a) * (a))
#define vit vector<int>::iterator
#define sit set<int>::iterator
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
typedef deque<int> dqi;
typedef queue<int> qi;
typedef queue<pii> qpii;
int GCD(int a, int b) { return !b ? a : GCD(b, a % b); }
inline double DIST(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
inline int DEC(char x) { return (int)(x - '0'); }
//==========================================================================================================================

//https://codeforces.com/problemset/problem/580/C
/**
** Comment **
**/

vi posCat, cntCat;
vb vs;
vvi grp;

inline void BFS(int m) {
	qi q;
	q.push(1);
	vs[1] = true;
	cntCat[1] += (posCat[1] == 1);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < grp[u].size(); ++i) {
			int v = grp[u][i];

			if (!vs[v]) {
				vs[v] = true;
				cntCat[v] += (posCat[v] ? cntCat[u] + 1 : 0);

				if (cntCat[v] <= m) {
					q.push(v);
				}
			}
		}
	}
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	int n, m, res = 0; cin >> n >> m;
	posCat = vi(n + 10);
	cntCat = vi(n + 10, 0);
	vs = vb(n + 10, false);
	grp = vvi(n + 10);

	for (int i = 1; i <= n; ++i) {
		cin >> posCat[i];
	}

	for (int u, v, i = 1; i < n; ++i) {
		cin >> u >> v;
		grp[u].push_back(v);
		grp[v].push_back(u);
	}

	BFS(m);
	for (int i = 2; i <= n; ++i) {
		if (!vs[i] || grp[i].size() != 1 || cntCat[i] > m) {
			continue;
		}
		++res;
	}
	cout << res << endl;

	return 0;
}
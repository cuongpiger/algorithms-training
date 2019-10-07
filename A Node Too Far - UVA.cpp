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
#include <string.h>
using namespace std;

//==========================================================================================================================
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
//==========================================================================================================================

/**
https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=272
** Comment **
**/

inline int bfs(int src, int weigth, vi grp[], int dist[]) {
	int cnt = 1;
	qi q;
	q.push(src);
	dist[src] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < grp[u].size(); ++i) {
			int v = grp[u][i];

			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;

				if (dist[v] <= weigth) {
					cnt += 1;

					if (dist[v] < weigth) {
						q.push(v);
					}
				}
			}
		}
	}

	return cnt;
}

int main() {
	//FAST_IO;
	//FILE_IO;
		
	int n, cs = 0;

	while (scanf("%d", &n) && n) {
		int noNode = 0;
		map<int, int> nw;
		vi grp[35];

		for (int u, v, i = 0; i < n; ++i) {
			scanf("%d %d", &u, &v);

			if (!nw.count(u)) {
				nw[u] = noNode++;
			}

			if (!nw.count(v)) {
				nw[v] = noNode++;
			}

			grp[nw[u]].push_back(nw[v]);
			grp[nw[v]].push_back(nw[u]);
		}

		int u, w;
		int dist[35];

		while (scanf("%d %d", &u, &w) && (u || w)) {
			memset(dist, -1, sizeof(dist));
			int res = 0;

			if (nw.count(u)) {
				res = bfs(nw[u], w, grp, dist);
			}
			
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++cs, noNode - res, u, w);
		}
	}

	return 0;
}
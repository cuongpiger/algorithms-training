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
http://www.lightoj.com/volume_showproblem.php?problem=1174
** Comment **
**/

#define distance first
#define vertex second
const int INF = 99999999;
vpii grp[105];

struct option {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
		return a.first > b.first;
	}
};

vi dijkstra(int s, int V) {
	vi dist(V + 5, INF);
	dist[s] = 0;
	priority_queue<pii, vpii, option> pq;
	pq.push(pii(0, s));

	while (!pq.empty()) {
		pii u = pq.top();
		pq.pop();

		if (u.distance != dist[u.vertex]) {
			continue;
		}

		for (int i = 0; i < grp[u.vertex].size(); ++i) {
			pii v = grp[u.vertex][i];

			if (dist[v.vertex] > u.distance + v.distance) {
				dist[v.vertex] = u.distance + v.distance;
				pq.push(pii(dist[v.vertex], v.vertex));
			}
		}
	}

	return dist;
}

int main() {
	FAST_IO;
	//FILE_IO;

	int tc;
	cin >> tc;

	for (int cs = 1; cs <= tc; ++cs) {
		int V, E, s, d;
		cin >> V >> E;

		for (int u, v, i = 0; i < E; ++i) {
			cin >> u >> v;
			grp[u].push_back(pii(1, v));
			grp[v].push_back(pii(1, u));
		}
		cin >> s >> d;

		vi distS = dijkstra(s, V);
		vi distD = dijkstra(d, V);
		int res = 0;

		for (int castle = 0; castle < V; ++castle) {
			res = max(res, distS[castle] + distD[castle]);
			grp[castle].clear();
		}

		cout << "Case " << cs << ": " << res << endl;
	}
	
	return 0;
}
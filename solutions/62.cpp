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
typedef vector<vector<vector<int>>> vvvi;
typedef deque<int> dqi;
typedef queue<int> qi;
typedef queue<pii> qpii;
int GCD(int a, int b) { return !b ? a : GCD(b, a % b); }
inline double DIST(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
inline int DEC(char x) { return (int)(x - '0'); }
//==========================================================================================================================

//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
/**
** Comment **
**/

vi grp[1010];
int dist[1010];

void DFS(int s) {
	for (int i = 0; i < grp[s].size(); ++i) {
		int v = grp[s][i];

		if (!/* The `dist` array in the provided code is used to store the distance of each node from the
        starting node (node 1) in a graph. The DFS (Depth First Search) algorithm is used to traverse
        the graph and calculate the distance of each node from the starting node. */
        dist[v] && v != 1) {
			dist[v] = dist[s] + 1;
			DFS(v);
		}
	}
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	int n, m, pos, res = 6969, minDist = 6969;
	cin >> n;

	for (int u, v, i = 1; i < n; ++i) {
		cin >> u >> v;
		grp[u].push_back(v);
		grp[v].push_back(u);
	}

	DFS(1);
	cin >> m;

	while (m--) {
		cin >> pos;

		if (dist[pos]) {
			if (dist[pos] < minDist) {
				minDist = dist[pos];
				res = pos;
			}
			else if (dist[pos] == minDist) {
				res = min(res, pos);
			}
		}
	}
	cout << res << endl;
	
	return 0;
}
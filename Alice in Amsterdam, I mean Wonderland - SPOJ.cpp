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
https://www.spoj.com/problems/UCV2013B/
____________________________________________________________________________________________________________________________*/

const ll INF = 20000000000000ll;
const int MAX = 105;

typedef struct Node {
	int source, target;
	ll weight;

	Node(int _source, int _target, ll _weight) {
		source = _source;
		target = _target;
		weight = _weight;
	}
} Node;

int n;
vector<Node> grp;
ll dist[MAX][MAX];
bool negCycle[MAX][MAX];
string name[MAX];

inline void BellMan_Ford(int s) {
	for (int i = 0; i < n; ++i) {
		dist[s][i] = INF;
		negCycle[s][i] = false;
	}

	dist[s][s] = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < grp.size(); ++j) {
			int u = grp[j].source;
			int v = grp[j].target;
			ll w = grp[j].weight;

			if (dist[s][u] != INF && dist[s][v] > dist[s][u] + w) {
				dist[s][v] = dist[s][u] + w;

				if (i == n - 1) {
					negCycle[s][v] = true;
				}
			}
		}
	}
}

int main() {
	FAST_IO;
	//FILE_IO;

	int cs = 1;
	while (cin >> n && n != 0) {
		ll w;
		int qry;
		grp.clear();

		for (int i = 0; i < n; ++i) {
			cin >> name[i];

			for (int j = 0; j < n; ++j) {
				cin >> w;

				if (i == j) { // the case there is a track connect from a vertex to itself
					if (w > 0) { // if weight greater than 0, it means there is no track
						w = 0;
					}
					else if (w < 0) { // if weight less than 0, that means there is a negative cycle
						// will occur when reaching this vertex
						w = -INF;
					}
				}

				// if there is a track from a vertex to itself or
				// if there is a track connect between 2 vertex (O means there is no track) 
				if (i == j || w != 0) {
					grp.push_back(Node(i, j, w));
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			BellMan_Ford(i);
		}

		cin >> qry;
		cout << "Case #" << cs++ << ":\n";

		while (qry--) {
			int u, v;
			cin >> u >> v;

			if (negCycle[u][v]) {
				cout << "NEGATIVE CYCLE\n";
			}
			else {
				cout << name[u] << "-" << name[v] << " ";

				if (dist[u][v] == INF) {
					cout << "NOT REACHABLE\n";
				}
				else {
					cout << dist[u][v] << endl;
				}
			}
		}
	}

	return 0;
}

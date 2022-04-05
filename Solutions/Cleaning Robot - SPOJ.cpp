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
https://www.spoj.com/problems/CLEANRBT/
** Comment **
**/

const int X[] = { 0, -1, 0, 1 };
const int Y[] = { -1, 0, 1, 0 };
const int INF = 99999;
int m, n, cntDirty;
int dist[1030][25][25];
vstr grp;

typedef struct Node {
	int x, y, mask;

	Node(int _mask, int _x, int _y) {
		x = _x;
		y = _y;
		mask = _mask;
	}
} Node;

inline bool canGo(int px, int py) {
	if (px < 0 || px >= m || py < 0 || py >= n || grp[px][py] == 'x') {
		return false;
	}

	return true;
}

inline int bfs(int rbx, int rby) {
	int res = INF;
	queue<Node> q;
	q.push(Node(0, rbx, rby));
	dist[0][rbx][rby] = 0;
	
	while (!q.empty()) {
		Node u = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			Node v = Node(u.mask, u.x + X[i], u.y + Y[i]);

			if (canGo(v.x, v.y)) {
				if (isupper(grp[v.x][v.y])) {
					v.mask |= (1 << (grp[v.x][v.y] - 'A'));
				}

				if (dist[v.mask][v.x][v.y] > dist[u.mask][u.x][u.y] + 1) {
					dist[v.mask][v.x][v.y] = dist[u.mask][u.x][u.y] + 1;

					if (v.mask == (1 << cntDirty) - 1) {
						res = min(res, dist[v.mask][v.x][v.y]);
					}

					q.push(v);
				}
			}
		}
	}

	return res < INF ? res : -1;
}

inline void initDist() {
	for (int k = 0; k < (1 << cntDirty); ++k) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[k][i][j] = INF;
			}
		}
	}
}

int main() {
	FAST_IO;
	//FILE_IO;
	
	while (cin >> n >> m && n && m) {
		grp.clear();
		pii robot;
		cntDirty = 0;
		grp.resize(m);

		for (int i = 0; i < m; ++i) {
			cin >> grp[i];

			for (int j = 0; j < n; ++j){
				if (grp[i][j] == 'o') {
					robot = pii(i, j);
				}
				else if (grp[i][j] == '*') {
					grp[i][j] = (char)('A' + cntDirty++);
				}
			}
		}

		initDist();
		cout << bfs(robot.first, robot.second) << endl;
	}

	return 0;
}
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

//https://www.spoj.com/problems/CATM/
/**
** Comment **
**/

#define x first
#define y second
const int X[] = { 0, -1, 0, 1 };
const int Y[] = { -1, 0, 1, 0 };

inline bool canGo(pii pos, int m, int n) {
	if (pos.x < 0 || pos.x >= m || pos.y < 0 || pos.y >= n) {
		return 0;
	}
	return true;
}

inline void BFS(vvvi &dist, pii pos, int m, int n, int id) {
	qpii q;
	q.push(pos);

	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			pii next = { u.x + X[i], u.y + Y[i] };

			if (canGo(next, m, n) && !dist[id][next.x][next.y]) {
				dist[id][next.x][next.y] = dist[id][u.x][u.y] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	int m, n, k; cin >> m >> n >> k;

	while (k--) {
		vpii pos(3);
		vvvi dist(3, vvi(m, vi(n, 0)));
		bool res = false; // 0 is mouse, 1 is first cat and 2 is second cat
		cin >> pos[0].x >> pos[0].y >> pos[1].x >> pos[1].y >> pos[2].x >> pos[2].y;

		for (int i = 0; i < 3; ++i) {
			pos[i].x -= 1;
			pos[i].y -= 1;
			BFS(dist, pos[i], m, n, i);
		}

		for (int j = 0; j < n; ++j) {
			if ((dist[0][0][j] < dist[1][0][j] && dist[0][0][j] < dist[2][0][j]) ||
				(dist[0][m - 1][j] < dist[1][m - 1][j] && dist[0][m - 1][j] < dist[2][m - 1][j])) {
				res = true;
				break;
			}
		}

		for (int i = 1; i < m - 1 && !res; ++i) {
			if ((dist[0][i][0] < dist[1][i][0] && dist[0][i][0] < dist[2][i][0]) ||
				(dist[0][i][n - 1] < dist[1][i][n - 1] && dist[0][i][n - 1] < dist[2][i][n - 1])) {
				res = true;
				break;
			}
		}

		if (res) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
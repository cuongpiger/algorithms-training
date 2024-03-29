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

//https://www.spoj.com/problems/UCV2013H/
/**
** Comment **
**/

#define x first
#define y second

const int X[] = { 0, 1, 0, -1 };
const int Y[] = { -1, 0, 1, 0 };
int beach[260][260];
int slicks[62510];

inline bool canGo(int i, int j, int m, int n) {
	if (i < 0 || i >= m || j < 0 || j >= n) {
		return false;
	}
	return true;
}

inline int BFS(int m, int n, vvb& vs, pii start) {
	qpii q;
	int cnt = 1;
	vs[start.x][start.y] = true;
	q.push({ start.x, start.y });

	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			pii next = { u.x + X[i], u.y + Y[i] };

			if (canGo(next.x, next.y, m, n) && !vs[next.x][next.y] && beach[next.x][next.y] == 1) {
				vs[next.x][next.y] = true;
				q.push({ next.x, next.y });
				++cnt;
			}
		}
	}

	return cnt;
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	int m, n;

	while (cin >> m >> n && m && n) {
		slicks[m * n] = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> beach[i][j];
				slicks[i * m + j] = 0;
			}
		}

		vvb vs(m, vb(n, false));
		set<int> res;
		int cnt = 0;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!vs[i][j] && beach[i][j] == 1) {
					int tmp = BFS(m, n, vs, { i, j });
					res.insert(tmp);
					++slicks[tmp];
					++cnt;
				}
			}
		}

		cout << cnt << endl;
		for (sit it = res.begin(); it != res.end(); ++it) {
			cout << *it << " " << slicks[*it] << endl;
		}
	}

	return 0;
}
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

//https://www.spoj.com/problems/MLASERP/
/**
** Comment **
**/

#define x first
#define y second
const int X[] = { 0, -1, 0, 1 };
const int Y[] = { -1, 0, 1, 0 };

int m, n;
char mp[110][110];
bool vs[110][110];
vpii pCow;

inline bool canGo(pii pos) {
	if (pos.x < 0 || pos.x >= m || pos.y < 0 || pos.y >= n || mp[pos.x][pos.y] == '*') {
		return false;
	}

	return true;
}

inline int bfs() {
	qpii q;
	q.push(pCow[0]);
	vs[pCow[0].x][pCow[0].y] = true;

	for (int cnt = -1; !q.empty(); ++cnt) {
		for (int i = 0, sz = q.size(); i < sz; ++i) {
			pii u = q.front();
			q.pop();

			if (u == pCow[1]) {
				return cnt;
			}

			for (int i = 0; i < 4; ++i) {
				for (pii v = u; canGo(v); v.x += X[i], v.y += Y[i]) {
					if (!vs[v.x][v.y]) {
						q.push(v);
						vs[v.x][v.y] = true;
					}
				}
			}
		}
	}
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mp[i][j];

			if (mp[i][j] == 'C') {
				pCow.push_back(pii(i, j));
			}
		}
	}
	
	int res = bfs();
	cout << res << endl;

	return 0;
}
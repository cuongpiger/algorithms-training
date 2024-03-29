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

//https://codeforces.com/problemset/problem/723/D
/**
** Comment **
**/

#define x first
#define y second
#define count first
#define position second
const int X[] = { 0, -1, 0, 1 };
const int Y[] = { -1, 0, 1, 0 };

int m, n, k;
bool vs[55][55];
string mp[55];
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> lakes;

inline bool canGo(pii pos) {
	if (pos.x < 0 || pos.x >= m || pos.y < 0 || pos.y >= n) {
		return false;
	}
	return true;
}

int DFS(pii s, char ch, char fill, bool cmp) {
	if (!canGo(s)) {
		return 0;
	}

	int cnt = 1;
	vs[s.x][s.y] = cmp;
	mp[s.x][s.y] = fill;

	for (int i = 0; i < 4; ++i) {
		pii next = { s.x + X[i], s.y + Y[i] };

		if (canGo(next) && mp[next.x][next.y] == ch && vs[next.x][next.y] == !cmp) {
			cnt += DFS(next, ch, fill, cmp);
		}
	}

	return cnt;
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	int cnt = 0;
	cin >> m >> n >> k;

	for (int i = 0; i < m; ++i) {
		cin >> mp[i];
	}

	for (int i = 0; i < m; ++i) {
		if (mp[i][0] == '.' && !vs[i][0]) {
			DFS({ i, 0 }, '.', '.', true);
		}

		if (mp[i][n - 1] == '.' && !vs[i][n - 1]) {
			DFS({ i, n - 1 }, '.', '.', true);
		}
	}

	for (int j = 1; j < n - 1; ++j) {
		if (mp[0][j] == '.' && !vs[0][j]) {
			DFS({ 0, j }, '.', '.', true);
		}

		if (mp[m - 1][j] == '.' && !vs[m - 1][j]) {
			DFS({ m - 1, j }, '.', '.', true);
		}
	}

	for (int i = 1; i < m - 1; ++i) {
		for (int j = 1; j < n - 1; ++j) {
			if (mp[i][j] == '.' && !vs[i][j]) {
				pair<int, pii> tmp;
				tmp.position = { i, j };
				tmp.count = DFS({ i, j }, '.', '.', true);
				lakes.push(tmp);
			}
		}
	}

	while (lakes.size() > k) {
		pair<int, pii> top = lakes.top();
		lakes.pop();
		cnt += top.count;
		DFS(top.position, '.', '*', false);
	}

	cout << cnt << endl;
	for (int i = 0; i < m; ++i) {
		cout << mp[i] << endl;
	}

	return 0;
}
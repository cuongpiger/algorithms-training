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

//=========================================================================================================================
#define pw(a) ((a) * (a))
#define vit vector<int>::iterator
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
//=========================================================================================================================

//http://lightoj.com/volume_showproblem.php?problem=1012
/**
** Comment **
**/

#define x first
#define y second

const int X[] = { 0, -1, 0, 1 };
const int Y[] = { -1, 0, 1, 0 };
char land[20][20];

inline bool canGo(int i, int j, int m, int n) {
	if (i < 0 || i >= m || j < 0 || j >= n) {
		return false;
	}
	return true;
}

inline int BFS(int m, int n, vvb& vs, pii sta) {
	int cnt = 1;
	qpii q; 
	q.push({ sta.x, sta.y });
	vs[sta.x][sta.y] = true;

	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nextX = u.x + X[i];
			int nextY = u.y + Y[i];

			if (canGo(nextX, nextY, m, n) && !vs[nextX][nextY] && land[nextX][nextY] == '.') {
				vs[nextX][nextY] = true;
				q.push({ nextX, nextY });
				++cnt;
			}
		}
	}
	
	return cnt;
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	int tc; cin >> tc;

	for (int cs = 1; cs <= tc; ++cs) {
		int n, m; cin >> n >> m;
		pii prc;
		vvb vs(20, vb(20, false));

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> land[i][j];

				if (land[i][j] == '@') {
					land[i][j] = '.';
					prc = { i, j };
				}
			}
		}

		cout << "Case " << cs << ": " << BFS(m, n, vs, prc) << endl;
	}
	
	return 0;
}
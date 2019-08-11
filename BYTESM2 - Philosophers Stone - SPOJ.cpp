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

//=============================================================================================
#define pw(a) ((a) * (a))
#define _x first
#define _y second
#define vit vector<int>::iterator
#define _cin(X) int (X); cin >> X
#define _FILE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define _FAST ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define _i(X) (int)(X)
const double pi = 3.14159265359;
typedef uint64_t uit;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
typedef vector<bool> vbool;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<vector<int>> vvint;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=============================================================================================

//https://www.spoj.com/problems/BYTESM2/
/**
** Comment **
**/

int mtx[100][102];

int main() {
	_FAST;
	_cin(tc);

	int h, w, res;

	while (tc--) {
		cin >> h >> w;
		res = 0;

		for (int i = 0; i < h; ++i) {
			mtx[i][0] = mtx[i][w + 1] = 0;
			for (int j = 1; j <= w; ++j) {
				cin >> mtx[i][j];
			}
		}

		for (int i = 1; i < h; ++i) {
			for (int j = 1; j <= w; ++j) {
				int maxW = max(mtx[i - 1][j], max(mtx[i - 1][j - 1], mtx[i - 1][j + 1]));
				mtx[i][j] += maxW;
			}
		}

		for (int i = 1; i <= w; ++i) res = max(res, mtx[h - 1][i]);
		cout << res << endl;
	}

	return 0;
}

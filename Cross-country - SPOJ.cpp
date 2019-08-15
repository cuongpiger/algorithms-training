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
typedef long long int lli;
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
typedef vector<pii> vpii;
typedef vector<vector<int>> vvint;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=============================================================================================

//https://www.spoj.com/problems/CRSCNTRY/
/**
 ** Comment **
 **/

int lcs[1010][1010];

inline int LCS(const vint& agness, const vint& other, int m, int n) {
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == 0 || j == 0)
				lcs[i][j] = 0;
			else if (agness[i - 1] == other[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	return lcs[m][n];
}

inline int solve(const vint& agness, const vvint& others) {
	int res = 0;
	for (int i = 0; i < others.size(); ++i) {
		res = max(res, LCS(agness, others[i], agness.size(), others[i].size()));
	}
	return res;
}

int main() {
	_FAST;
	_cin(tc);

	while (tc--) {
		vint agness;
		vvint others;
		int tmp;

		while (cin >> tmp && tmp) {
			agness.push_back(tmp);
		}

		while (true) {
			vint maleRunner;
			while (cin >> tmp && tmp) {
				maleRunner.push_back(tmp);
			}

			if (maleRunner.size()) others.push_back(maleRunner);
			else break;
		}

		cout << solve(agness, others) << endl;
	}

	return 0;
}

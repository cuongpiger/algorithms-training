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
#define _cin(X) int (X); cin >> X
#define _FILE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define _FAST ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define _i(X) (int)(X)
const double pi = 3.14159265359;
const long long mod = 1e9 + 7;
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
typedef pair<ll, string> plls;
typedef vector<bool> vbool;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvint;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
//=========================================================================================================================

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503
/**
** Comment **
**/

vint dp;

inline int knapsack(vint& a, int n, int w) {
	dp.assign(250005, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = w; j >= 0; --j) {
			/*Why we have to go from w to 0, if we go from 0 to w, we will recall the
			previous calculation of <dp[j - a[i]]>, not the previous result of (i - 1), example with this
			test case: 1 1 1 1 11*/
			if (a[i] <= j) {
				dp[j] = max(dp[j], a[i] + dp[j - a[i]]);
			}
		}
	}

	return dp[w];
}

int main() {
	_FAST;
	_cin(tc);

	while (tc--) {
		_cin(n);
		int sum = 0;
		vint coins(n);

		for (int i = 0; i < n; ++i) {
			cin >> coins[i];
			sum += coins[i];
		}

		cout << sum - 2 * knapsack(coins, n, sum / 2) << endl;
	}

	return 0;
}
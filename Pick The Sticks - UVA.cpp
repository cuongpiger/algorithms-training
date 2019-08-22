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
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvint;
typedef vector<vector<long long>> vvll;
typedef vector<vector<vector<int>>> vvvint;
typedef vector<vector<vector<long long>>> vvvll;
typedef vector<vector<pii>> vvpii;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
//=========================================================================================================================

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4867
/**
** Comment **
**/

#define length first
#define value second
ll dp[1005][4010][3];  // the stick i-th, length, {in w, 1 stick at half, 2 sticks at half}
pii sticks[1005];

int main() {
	_FAST;
	_cin(tc);

	for (int cs = 1; cs <= tc; ++cs) {
		_cin(n); _cin(w);
		ll res = 0;
		w *= 2;

		for (int i = 0; i < 1005; ++i) {
			for (int j = 0; j < 4010; ++j) {
				for (int k = 0; k < 3; ++k) {
					dp[i][j][k] = 0;
				}
			}
		}

		for (int i = 1; i <= n; ++i) {
			cin >> sticks[i].length >> sticks[i].value;
			res = max(res, 1LL*sticks[i].value); // balance case
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= w; ++j) {
				for (int k = 0; k <= 2; ++k) { // side
					dp[i][j][k] = dp[i - 1][j][k];

					if (j >= 2 * sticks[i].length) {
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 2 * sticks[i].length][k] + sticks[i].value);
					}

					if (j >= sticks[i].length && k) {
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - sticks[i].length][k - 1] + sticks[i].value);
					}
				}
			}
		}

		for (int k = 0; k <= 2; ++k) {
			res = max(res, dp[n][w][k]);
		}

		cout << "Case #" << cs << ": " << res << endl;
	}

	return 0;
}
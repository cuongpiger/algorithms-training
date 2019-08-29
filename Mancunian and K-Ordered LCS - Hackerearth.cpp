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
typedef vector<bool> vbool;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pdi> vpdi;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvint;
typedef vector<vector<long long>> vvll;
typedef vector<vector<vector<int>>> vvvint;
typedef vector<vector<vector<long long>>> vvvll;
typedef vector<vector<pii>> vvpii;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
//=========================================================================================================================

//https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
/**
** Comment **
**/

int dp[2010][2010][10];

int main() {
	_FAST;
	_cin(n); _cin(m); _cin(k);
	vint a = vint(n), b = vint(m);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int j = 0; j < m; ++j) {
		cin >> b[j];
	}
	
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int l = 0; l <= k; ++l) {
				if (!i || !j) {
					dp[i][j][l] = 0;
				}
				else if (a[i - 1] == b[j - 1]) {
					dp[i][j][l] = dp[i - 1][j - 1][l] + 1;
				}
				else {
					dp[i][j][l] = max(dp[i - 1][j][l], dp[i][j - 1][l]);

					if (l) {
						dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][l - 1] + 1);
					}
				}
			}
		}
	}

	cout << dp[n][m][k] << endl;

	return 0;
}
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
typedef pair<ll, string> plls;
typedef vector<bool> vbool;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvint;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=============================================================================================

//https://www.spoj.com/problems/ADFRUITS/
/**
** Comment **
 **/

inline string solve(const string& s1, const string& s2) {
	int m = s1.size(), n = s2.size();
	vvint dp(m + 1, vint(n + 1));

	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (!i || !j) dp[i][j] = 0;
			else if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int len = dp[m][n];
	string lcs; lcs.resize(len);
	int i = m, j = n;

	while (i > 0 && j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			lcs[len - 1] = s1[i - 1];
			--i, --j, --len;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) --i;
		else --j;
	}

	return lcs;
}

inline void print(const string& s1, const string& s2) {
	string lcs = solve(s1, s2);
	int i = 0, j = 0;

	for (int k = 0; k < lcs.size(); ++k) {
		while (s1[i] != lcs[k]) {
			cout << s1[i++];
		}

		while (s2[j] != lcs[k]) {
			cout << s2[j++];
		}

		cout << lcs[k];
		++i, ++j;
	}

	while (i < s1.size()) {
		cout << s1[i++];
	}

	while (j < s2.size()) {
		cout << s2[j++];
	}
	cout << endl;
}

int main() {
	_FAST;
	string s1, s2;

	while (cin >> s1) {
		cin >> s2;
		print(s1, s2);
	}

	return 0;
}

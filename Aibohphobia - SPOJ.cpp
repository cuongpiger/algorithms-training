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

/**
https://www.spoj.com/problems/AIBOHP/
 ** Comment **
https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/
 **/
 
inline int solve(const string& s) {
	int n = s.size();
	vvint dp(n, vint(n, 0));
 
	for (int gap = 1; gap < n; ++gap) {
		for (int l = 0, h = gap; h < n; ++l, ++h) {
			dp[l][h] = (s[l] == s[h] ? dp[l + 1][h - 1] : (min(dp[l][h - 1], dp[l + 1][h]) + 1));
		}
	}
 
	return dp[0][n - 1];
}
 
int main() {
	_FAST;
	_cin(tc);
	string s;
 
	while (tc--) {
		cin >> s;
		cout << solve(s) << endl;
	}
 
	return 0;
} 

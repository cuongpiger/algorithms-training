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
typedef vector < vector<vector<int>>> vvvint;
typedef vector<vector<pii>> vvpii;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
//=========================================================================================================================

//https://www.spoj.com/problems/SCUBADIV/
/**
** Comment **
**/

vvvint dp; // the index of the cyderlin i-th, oxygen, nitrogen
vint oxy, nitro, weight;

int knapsack(int i, int oxyNeed, int nitroNeed) {
	if (dp[i][oxyNeed][nitroNeed] != -1) {
		return dp[i][oxyNeed][nitroNeed];
	}
		
	if (!oxyNeed && !nitroNeed) {
		dp[i][oxyNeed][nitroNeed] = 0;
		return dp[i][oxyNeed][nitroNeed];
	}

	if (!i) {
		dp[i][oxyNeed][nitroNeed] = 100000000;
	}
	else {
		int newOxyNeed = max(0, oxyNeed - oxy[i]);
		int newNitroNeed = max(0, nitroNeed - nitro[i]);
		int getThisCylinder = knapsack(i - 1, newOxyNeed, newNitroNeed) + weight[i];
		int dontGetThisCylinder = knapsack(i - 1, oxyNeed, nitroNeed);
		dp[i][oxyNeed][nitroNeed] = min(getThisCylinder, dontGetThisCylinder);
	}

	return dp[i][oxyNeed][nitroNeed];
}

int main() {
	_FAST;
	_cin(tc);

	while (tc--) {
		_cin(oxygen); _cin(nitrogen); _cin(n);
		oxy = vint(n + 1, 0);
		nitro = vint(n + 1, 0);
		weight = vint(n + 1, 0);
		dp = vvvint(1005, vvint(25, vint(85, -1)));

		for (int i = 1; i <= n; ++i) {
			cin >> oxy[i] >> nitro[i] >> weight[i];
		}
		cout << knapsack(n, oxygen, nitrogen) << endl;
	}

	return 0;
}
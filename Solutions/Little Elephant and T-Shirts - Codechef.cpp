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
#define _x first
#define _y second
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
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=========================================================================================================================

//https://www.codechef.com/problems/TSHIRTS
/**
** Comment **
https://www.geeksforgeeks.org/bitmasking-and-dynamic-programming-set-1-count-ways-to-assign-unique-cap-to-every-person/
**/

vvint shirtList, dp;
int allmask;

lli countWaysUtil(int mask, int i) {
	if (mask == allmask) return 1;
	if (i > 100) return 0;
	if (dp[mask][i] != -1) return dp[mask][i];

	lli ways = countWaysUtil(mask, i + 1);
	for (int j = 0; j < shirtList[i].size(); ++j) {
		if (!(mask & (1 << shirtList[i][j]))) {
			ways += countWaysUtil(mask | (1 << shirtList[i][j]), i + 1);
			ways %= mod;
		}
	}

	return dp[mask][i] = ways;
}

inline void countWay(int n) {
	string tmp, str;
	int x;
	shirtList.clear(), shirtList.resize(101, vint());
	dp.clear(), dp.resize(1025, vint(101, -1));
	allmask = (1 << n) - 1;

	getline(cin, str);
	for (int i = 0; i < n; ++i) {
		getline(cin, str);
		stringstream ss(str);

		while (ss >> tmp) {
			stringstream s;
			s << tmp;
			s >> x;
			shirtList[x].push_back(i);
		}
	}

	cout << countWaysUtil(0, 1) << endl;
}

int main() {
	_FAST;
	_cin(tc);

	while (tc--) {
		_cin(n);
		countWay(n);
	}

	return 0;
}

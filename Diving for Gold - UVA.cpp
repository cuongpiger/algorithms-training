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

//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=931
/**
** Comment **
**/

#define time first
#define gold second
vvint dp;

inline int knapsack(vpii& a, int t) {
	dp.assign(a.size() + 1, vint(t + 1, 0));
	for (int i = 1; i < a.size(); ++i) {
		for (int j = 0; j <= t; ++j) {
			if (a[i].time > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				int tmp1 = a[i].gold + dp[i - 1][j - a[i].time];
				int tmp2 = dp[i - 1][j];
				dp[i][j] = max(tmp1, tmp2);
			}
		}
	}

	return dp[a.size() - 1][t];
}

void printItems(vpii& a, int t, int index, int w, int cnt) {
	pii res = { -1, -1 };

	if (index <= 0) {
		cout << cnt << "\n";
		return;
	}

	if (index > 0) {
		if (dp[index][t] != dp[index - 1][t]) {
			res = a[index];
			cnt += 1;
			printItems(a, t - a[index].time, index - 1, w, cnt);
		}
		else {
			printItems(a, t, index - 1, w, cnt);
		}
	}

	if (res.time != -1) {
		cout << res.time/(3*w) << " " << res.gold << "\n";
	}
}

int main() {
	_FAST;
	int t, w, n;
	string br = "";

	while (cin >> t >> w >> n) {
		vpii tre(n + 1, {0, 0});

		for (int i = 1; i <= n; ++i) {
			cin >> tre[i].time >> tre[i].gold;
			tre[i].time *= (3 * w);
		}

		cout << br << knapsack(tre, t) << "\n";
		printItems(tre, t, tre.size() - 1, w, 0);
		br = "\n";
	}

	return 0;
}

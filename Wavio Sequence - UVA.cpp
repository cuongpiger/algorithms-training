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

//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1475
/**
** Comment **
**/

inline vint LCS(const vint& a) {
	vint len(a.size()), truck;

	for (int i = 0; i < a.size(); ++i) {
		int pos = lower_bound(truck.begin(), truck.end(), a[i]) - truck.begin();
		if (pos == truck.size()) 
			truck.push_back(a[i]);
		else 
			truck[pos] = a[i];

		len[i] = pos + 1;
	}

	/*for (int i = 0; i < len.size(); ++i) {
		cout << len[i] << " ";
	}

	cout << "\n";*/

	return len;
}

int main() {
	_FAST;
	int n;
	
	while (cin >> n) {
		int ans = 1;
		vint num(n);
		for (int i = 0; i < n; ++i) {
			cin >> num[i];
		}

		vint lcs1 = LCS(num);
		reverse(num.begin(), num.end());
		vint lcs2 = LCS(num);

		for (int i = 0; i < n; ++i) {
			int lowest = min(lcs1[i], lcs2[n - i - 1]);
			ans = max(ans, (lowest * 2) - 1);
		}

		cout << ans << "\n";
	}
	
	return 0;
}
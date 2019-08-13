#pragma warning(disable:4996)
#include <iostream>
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
using namespace std;

//=============================================================================================
#define pw(a) ((a) * (a))
#define _x first
#define _y second
#define vit vector<int>::iterator
#define _cin(X) int (X); cin >> X
#define _FILE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define _FAST ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
const double pi = 3.14159265359;
typedef long long ll;
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
typedef vector<vector<int>> vvint;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=============================================================================================

//https://www.codechef.com/problems/PPXOR
/**
** Comment **
**/

int main() {
	_FAST;
	_cin(tc);

	while (tc--) {
		_cin(n);
		vll a(n + 1);
		ll res = 0;
		a[0] = 0;
		for (ll x = 1; x <= n; x++) {
			cin >> a[x];
			a[x] ^= a[x - 1];
		}

		for (ll x = 30; x >= 0; x--) {
			ll cnt = 0, t = 1 << x;

			for (ll i = 0; i <= n; i++)
				if (a[i] & t) cnt++;

			res += ((ll)cnt * (ll)(n - cnt + 1) * (ll)t);
		}

		cout << res << endl;
	}
	
	return 0;
}

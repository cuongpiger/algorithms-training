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
typedef vector<vector<int>> vvint;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=============================================================================================

//https://practice.geeksforgeeks.org/problems/examination-papers/0
/**
** Comment **
**/

const ll mod = (ll)1e9 + 7;

inline ll fermat(ll deno, ll subMod) {
	ll res = 1;
	deno %= mod;

	while (subMod > 0) {
		if (subMod & 1) res = (res * deno) % mod;
		subMod >>= 1;
		deno = pw(deno) % mod;
	}

	return res - 1;
}

// Big-O online judge
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//
//	_cin(tc);
//	while (tc--) {
//		ll k;
//		cin >> k;
//		cout << fermat(2, k) << endl;
//	}
//
//	return 0;
//}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	_cin(tc);
	while (tc--) {
		ll n; cin >> n;
		cout << (((ll)1 << n) - 1) << endl;
	}

	return 0;
}

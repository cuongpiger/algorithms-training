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
int _gcd(int a, int b) { return !b ? a : _gcd(b, a %b); }
inline double _distance(const pii &a, const pii &b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=============================================================================================
//https://www.hackerrank.com/challenges/longest-increasing-subsequence-arrays/problem
/**
** Comment **
Ideas for this problem:
- Supposed to take m = 5 and n = 3, then we will have C(n, k) = C(m, n) ways to place numbers from 1 to n in range from 1 to m
- C(5, 3) = 10 ways include
	1 2 3 ? ?
	1 2 ? 3 ?
	1 2 ? ? 3
	1 ? 2 3 ?
	1 ? 2 ? 3
	1 ? ? 2 3
	? 1 2 3 ?
	? 1 2 ? 3
	? 1 ? 2 3
	? ? 1 2 3
=> So how do we put numbers in the remaining positions? I call p is the index of the element equal to n.
1 2 ? 3 ?. In this example p = 4 (array start from 1 to <= m). So the positions in front of p can only be 
less than or equal to n - 1, because p is the index of the largest number of LIS array and p at the last of LIS
array, so from 1 to n - 1, there are C(p - 1, n - 1) ways to choose positions to place number from 1 to less than n,
because n is at p so we don't need to count it. After then we have [(p - 1) - (p - 1)] positions to place the remaining 
numbers from 1 to less than n - 1 which are not elements of LIS array, and after p are free positions, any value can be set
between from 1 to equal to n, therefore have m - p position to place and we have pow(n, m - p) ways to place
**/

const ll mod = (ll)(1e9 + 7);
ll fact[(int)5e5 + 5];
ll invFact[(int)5e5 + 5];

inline ll fermat(ll deno, ll subMod) {
	ll res = 1;
	deno %= mod;

	while (subMod > 0) {
		if (subMod & 1) res = (res * deno) % mod;
		subMod >>= 1;
		deno = pw(deno) % mod;
	}

	return res;
}

inline void initializeFactorial() {
	fact[0] = invFact[0] = 1;

	for (int i = 1; i < (int)5e5 + 5; ++i) {
		fact[i] = (fact[i - 1] * i) % mod;
		invFact[i] = fermat(fact[i], mod - 2)%mod;
	}
}

inline ll nCr(ll n, ll r) {
	ll numerator = fact[n];
	ll denominator = (invFact[n - r] * invFact[r]) % mod;
	return numerator * denominator % mod;
}
																								
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	initializeFactorial();

	_cin(tc);
	while (tc--) {
		_cin(m); _cin(n);
		ll ans = 0;
		vector<ll> powerN(m + 1, 1), powerNsub1(m + 1, 1);

		for (int i = 1; i <= m; ++i) {
			powerN[i] = (powerN[i - 1] * n) % mod;
			powerNsub1[i] = (powerNsub1[i - 1] * (n - 1)) % mod;
		}

		for (int p = n; p <= m; ++p) {
			ans += (((nCr(p - 1, n - 1)*powerN[m - p]) % mod)*(powerNsub1[(p - 1) - (n - 1)] % mod))%mod;
			ans %= mod;
		}

		cout << ans << endl;
	}

	return 0;
}

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
#define x first
#define y second
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
int _gcd(int a, int b){ return !b ? a : _gcd(b, a %b); }
double _distance(const pii &a, const pii &b){ return sqrt(pw((double)(a.x - b.x)) + pw((double)(a.y - b.y))); }
//=============================================================================================

//http://lightoj.com/volume_showproblem.php?problem=1102
/**
** Comment **
https://www.geeksforgeeks.org/modular-division/
**/
const ll mod = 1000000007;
ll fact[2000005];

inline void initializeFactorial(){
	fact[0] = 1;

	for (int i = 1; i <= 2000005; ++i){
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}
}

inline ll fermat(ll deno, ll subMod){
	ll res = 1;
	deno %= mod;

	while (subMod > 0){
		if (subMod & 1) res = (res *deno) % mod;
		subMod >>= 1;
		deno = (pw(deno)) % mod;
	}

	return res;
}

inline ll nCr(ll n, ll r){
	ll numerator = fact[n];
	ll denominator = (fact[n - r] * fact[r]) % mod;
	return numerator*fermat(denominator, mod - 2)%mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	initializeFactorial();
	int caseth = 1;
	int tc;

	scanf("%d", &tc);
	while (tc--){
		ll n, k;
		scanf("%lld %lld", &n, &k);
		n = n + k - 1;
		k = k - 1;
		printf("Case %d: %lld\n", caseth++, nCr(n, k));
	}

	return 0;
}

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
int _gcd(int a, int b){ return !b ? a : _gcd(b, a %b); }
inline double _distance(const pii &a, const pii &b){ return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=============================================================================================

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3055
/**
** Comment **
https://www.geeksforgeeks.org/modular-division/
https://uva.onlinejudge.org/board/viewtopic.php?f=54&t=51171&p=129834&hilit=11904&sid=e6abe98ef24e9ea29bc9da890ecf428f&fbclid=IwAR1u1s1Xvl3-8EXAISR2V1M3buvwkHPzuCNjyhjwG7zfCMMlv6aZpG3Lt_0#p129834
https://imgur.com/a/3ZNg255
**/

const ll mod = 1000000007;
ll fact[1001005];

inline void initializeFactorial(){
	fact[0] = 1;

	for (int i = 1; i <= 1001005; ++i){
		fact[i] = (fact[i - 1] * i) % mod;
	}
}

inline ll fermat(ll deno, ll subMod){
	ll res = 1;
	deno %= mod;

	while (subMod > 0){
		if (subMod & 1) res = (res * deno) % mod;
		subMod >>= 1;
		deno = (pw(deno)) % mod;
	}

	return res;
}

inline ll nCr(ll n, ll r){
	// https://imgur.com/gallery/9A5fbSh
	ll numerator = fact[n];
	ll denominator = (fact[n - r] * fact[r]) % mod;
	return numerator * fermat(denominator, mod - 2) % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	initializeFactorial();

	int caseth = 1;
	_cin(tc);

	while (tc--){
		_cin(n);
		ll sum = 0, cnt = 1;

		for (int i = 0; i < n; ++i){
			_cin(tmp);
			int N = (sum + tmp - 1) % mod;
			int K = (tmp - 1) % mod;
			cnt = cnt * nCr(N, K)%mod;
			sum += tmp;
		}

		cout << "Case " << caseth++ << ": " << cnt << endl;
	}
	
	return 0;
}

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

/**
** Comment **
**/

inline ll maxPrimeFactors(ll n) {
	ll maxPrime = -1;
	ll dividend = n;

	while (!(n % 2)) n >>= 1;

	for (int i = 3; i <= sqrtl(n); i += 2) {
		while (!(n % i)) {
			maxPrime = i;
			n /= i;
		}
	}

	if (n > 2) maxPrime = n;
	double tmp = log(dividend*1.0) / log(maxPrime*1.0);
	if (maxPrime != -1 && tmp == (ll)tmp) {
		maxPrime = -1;
	}

	return maxPrime;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	ll n;
	while (cin >> n && n) {
		cout << maxPrimeFactors(llabs(n)) << endl;
	}

	return 0;
}
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

/**
** Comment **
https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
**/

ll gcdExtended(ll a, ll b, ll &x, ll &y){
	if (!b){
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;
	ll gcd = gcdExtended(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1*(a / b);

	return gcd;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	_cin(tc);
	while (tc--){
		ll x, k, _floor, _ceil, a, b, gcd;
		cin >> x >> k;
		_floor = x / k;
		_ceil = x / k + ((x%k) != 0);
		gcd = gcdExtended(_floor, _ceil, a, b);
		a *= (x / gcd);
		b *= (x / gcd);
		cout << a << " " << b << endl;
	}

	return 0;
}
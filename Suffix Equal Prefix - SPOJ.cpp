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

//==============================================================================================
#define pw(a) ((a) * (a))
#define _x first
#define _y second
#define vit vector<int>::iterator
#define _cin(X) int (X); cin >> X
#define _FILE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define _FAST ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define _i(X) (int)(X)
const double pi = 3.14159265359;
typedef long long ll;
typedef unsigned long long ull;
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
//==============================================================================================

//https://www.spoj.com/problems/SUFEQPRE/
/**
** Comment **
https://imgur.com/gallery/JoWwo2w
https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming/
**/

const ll mod = 1e9 + 7;
ull substring[_i(1e6) + 10];
ull power[_i(1e6) + 10];
int n;

inline void initializePower() {
	power[0] = 1;
	for (int i = 1; i < 1e6 + 10; ++i) power[i] = (power[i - 1] * 33) % mod;
}

inline void polyHash(string& s) {
	ull hashValue = 0;
	n = s.length();
	for (int i = 0; i < n; ++i) {
		hashValue = ((s[i] - 'a') + (33 * hashValue) % mod) % mod;
		substring[i + 1] = hashValue;
	}
}

int main() {
	_FAST;
	initializePower();

	string s;
	_cin(tc);

	for (int t = 1; t <= tc; ++t) {
		cin >> s;
		int res = 0, leng = 1;
		polyHash(s);

		while (leng < n) {
			if (substring[leng] == ((substring[n] - (substring[n - leng] * power[leng]) % mod) + mod) % mod) ++res;
			++leng;
		}
		cout << "Case " << t << ": " << res << endl;
	}

	return 0;
}

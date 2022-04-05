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
#include <unordered_set>
#include <unordered_map>
using namespace std;

//=============================================================================================
#define pw(a) ((a) * (a))
#define _x first
#define _y second
#define vit vector<int>::iterator
#define _cin(X) int (X); cin >> X
#define _FILE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define _FAST ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define _i(X) (int)(X)
const double pi = 3.14159265359;
typedef uint64_t uit;
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
//=============================================================================================

//https://codeforces.com/problemset/problem/1137/B
/**
** Comment **
**/

#define b0 first
#define b1 second

const ll mod = 1e9 + 7;
ull subStr[_i(5e5 + 10)];
ull _pw[_i(5e5 + 10)];
pii cntS, cntT;
int n;

inline void polyHash(string& s) {
	ull hashValue = 0;
	n = s.length();
	_pw[0] = 1;

	for (int i = 0; i < n; ++i) {
		hashValue = (s[i] + (33 * hashValue) % mod) % mod;
		subStr[i + 1] = hashValue;
		_pw[i + 1] = (_pw[i] * 33) % mod;
	}
}

inline int findLengthSuffix(string& s) {
	polyHash(s);
	int len = 0, maxLen = 0;
	pii cntBit = { 0, 0 };

	while (++len < n) {
		s[len - 1] == '1' ? ++cntBit.b1 : ++cntBit.b0;
		if (subStr[len] == ((subStr[n] - (subStr[n - len] * _pw[len]) % mod) + mod) % mod) maxLen = len;
	}
	return maxLen;
}

inline pii subBit(const pii& a, const pii& b) {
	return { a.b0 - b.b0, a.b1 - b.b1 };
}

int main() {
	_FAST;
	string s, t;
	cin >> s >> t;

	for (int i = 0; i < s.length(); ++i) cntS.b1 += (s[i] == '1');
	for (int i = 0; i < t.length(); ++i) cntT.b1 += (t[i] == '1');
	cntS.b0 = s.size() - cntS.b1;
	cntT.b0 = t.size() - cntT.b1;

	if (cntS.b0 <= 0 || cntS.b1 <= 0 || cntS.b0 < cntT.b0 || cntS.b1 < cntT.b1 || s.size() < t.size()) {
		cout << s << endl;
	}
	else {
		int len = findLengthSuffix(t);
		string res = t;
		pii tmp = subBit(cntS, cntT), suffix;
		t.erase(0, len);

		for (int i = 0; i < t.size(); ++i) t[i] == '1' ? ++suffix.b1 : ++suffix.b0;
		while (subBit(tmp, suffix).b0 >= 0 && subBit(tmp, suffix).b1 >= 0) {
			res += t;
			tmp = subBit(tmp, suffix);
		}

		if (tmp.b0) res += string(tmp.b0, '0');
		if (tmp.b1) res += string(tmp.b1, '1');

		cout << res << endl;
	}

	return 0;
}

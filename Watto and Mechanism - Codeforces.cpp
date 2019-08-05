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

/**
** Comment **
https://imgur.com/gallery/AQcgnzG
**/

const ll mod = 1e9 + 7;
unordered_set<ll> truck;
ll _pw[_i(6e5 + 10)];

inline void initializePower() {
	_pw[0] = 1;
	for (int i = 1; i < 6e5 + 10; ++i) _pw[i] = (_pw[i - 1] * 257) % mod;
}

inline ll polyHash(const string& s) {
	ll hashValue = 0;
	for (int i = 0; i < s.size(); ++i) {
		hashValue = ((hashValue * 257) % mod + s[i]) % mod;
	}

	return hashValue;
}

inline bool checkSameString(const string& q) {
	ll hashValue = polyHash(q);
	int len = q.length();

	for (int i = 0; i < q.size(); ++i) {
		for (ll ch = 'a'; ch <= 'c'; ++ch) {
			if (q[i] == ch) continue;
			ll newHashValue = ((((ch - q[i]) * _pw[len - i - 1]) % mod + mod) % mod + hashValue) % mod;

			if (truck.find(newHashValue) != truck.end()) return true;
		}
	}

	return false;
}

int main() {
	_FAST;
	_cin(n); _cin(m);
	initializePower();
	string s;

	for (int i = 0; i < n; ++i) {
		cin >> s;
		truck.insert(polyHash(s));
	}

	for (int i = 0; i < m; ++i) {
		cin >> s;
		if (checkSameString(s)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
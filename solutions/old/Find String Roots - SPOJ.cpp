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

//=========================================================================================================================
#define pw(a) ((a) * (a))
#define vit vector<int>::iterator
#define _cin(X) int (X); cin >> X
#define _FILE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define _FAST ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define _i(X) (int)(X)
const double pi = 3.14159265359;
const long long mod = 1e9 + 7;
typedef uint64_t uit;
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
typedef pair<ll, string> plls;
typedef vector<bool> vbool;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvint;
typedef vector<vector<long long>> vvll;
typedef vector<vector<vector<int>>> vvvint;
typedef vector<vector<vector<long long>>> vvvll;
typedef vector<vector<pii>> vvpii;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
//=========================================================================================================================

//https://www.spoj.com/problems/FINDSR/
/**
** Comment **
**/

vint prefix;

inline int KMPpreprocess(const string& p) {
	prefix.assign(p.length(), 0);
	int m = p.length(), j = 0, i = 1, res = 1;

	while (i < m) {
		if (p[i] == p[j]) {
			prefix[i] = ++j;
			++i;
		}
		else {
			if (j) {
				j = prefix[j - 1];
			}
			else {
				prefix[i++] = 0;
			}
		}
	}

	int tmp = p.length() - prefix[p.length() - 1]; // the values at index which equal to 0
	// ex a b c a b c a b c a b c => 0 0 0 1 2 3 4 5 6 7 8 9

	if (tmp < p.length() && !(p.length() % tmp)) res = p.length() / tmp;
	return res;
}

int main() {
	_FAST;
	prefix = vint(1e5 + 10);
	string s;

	while (cin >> s && s[0] != '*') {
		cout << KMPpreprocess(s) << endl;
	}
	
	return 0;
}
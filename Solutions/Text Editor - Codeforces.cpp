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

//https://codeforces.com/gym/101466/problem/E
/**
** Comment **
**/

vint prefix;

inline void KMPpreprocess(const string& p) {
	prefix.resize(p.length(), 0);
	int m = p.length(), j = 0, i = 1;

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
}

inline int KMPsearch(const string &t, const string &p, int mid) {
	int n = t.length(), m = mid + 1, i = 0, j = 0, cnt = 0;
	while (i < n) {
		if (p[j] == t[i]) {
			++j, ++i;
		}

		if (j == m) {
			++cnt;
			j = prefix[j - 1];
		}
		else if (i < n && p[j] != t[i]) {
			if (j) {
				j = prefix[j - 1];
			}
			else {
				++i;
			}
		}
	}

	return cnt;
}

inline bool checkFunction(int k, int fence) {
	return fence >= k;
}

int main() {
	_FAST;
	string a, b;
	int k;
	getline(cin, a, '\n');
	getline(cin, b, '\n');
	cin >> k;
	KMPpreprocess(b);

	// binary search
	int right = b.length() - 1, left = 0, fence = -1;
	while (left <= right) {
		int mid = (left + right) >> 1;
		int tmp = KMPsearch(a, b, mid);

		if (checkFunction(k, tmp)) {
			fence = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	if (fence >= 0) {
		for (int i = 0; i <= fence; ++i) {
			cout << b[i];
		}
		cout << endl;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}
	
	return 0;
}
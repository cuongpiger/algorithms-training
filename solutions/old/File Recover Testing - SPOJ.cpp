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
const double pi = 3.14159265359;
const long long mod = 1e9 + 7;
typedef uint64_t uit;
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<double, int> pdi;
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
typedef vector<pdi> vpdi;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvint;
typedef vector<vector<long long>> vvll;
typedef vector<vector<vector<int>>> vvvint;
typedef vector<vector<vector<long long>>> vvvll;
typedef vector<vector<pii>> vvpii;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
//=========================================================================================================================

//https://www.spoj.com/problems/FILRTEST/
/**
** Comment **
**/

void KMPpreprocess(const string& p, vint& prefix) {
	prefix.resize(p.size(), 0);
	int m = p.length(), j = 0, i = 1;

	while (i < m) {
		if (p[i] == p[j]) {
			prefix[i++] = ++j;
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

int main() {
	_FAST;
	int n;

	while (cin >> n && n != -1) {
		string p;
		vint prefix;
		int res = 0;

		cin >> p;
		KMPpreprocess(p, prefix);

		if (n >= p.length()) {
			res = (n - prefix[p.length() - 1]) / (p.length() - prefix[p.length() - 1]);
		}

		cout << res << endl;
	}
	
	return 0;
}
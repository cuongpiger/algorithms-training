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
#define _x first
#define _y second
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
typedef vector<vector<int>> vvint;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=========================================================================================================================

//https://codeforces.com/problemsets/acmsguru/problem/99999/199
/**
** Comment **
**/

vint path, res;
typedef struct {
	int id, strength, beauty;
} mb;

inline int lowerBound(const vector<mb> &a, const vint &sub, int n, mb key){
	int l = 0, r = n, pos = r;

	while (l < r){
		int m = (l + r) / 2;
		int index = sub[m];

		if (a[index].beauty >= key.beauty){
			pos = r = m;
		}
		else{
			l = m + 1;
		}
	}

	return pos;
}

inline int LIS(const vector<mb> &a){
	int len = 1;
	path.assign(a.size(), -1);
	res.push_back(0);

	for (int i = 1; i < a.size(); ++i){
		if (a[i].beauty <= a[res[0]].beauty){
			res[0] = i;
		}
		else if (a[i].beauty > a[res[len - 1]].beauty){
			path[i] = res[len - 1];
			res.push_back(i);
			++len;
		}
		else {
			int pos = lowerBound(a, res, len, a[i]);
			path[i] = res[pos - 1];
			res[pos] = i;
		}
	}

	return len;
}

inline void printLIS(const vector<mb> &a){
	int len = LIS(a);
	int i = res[len - 1];

	cout << len << endl;
	while (i >= 0){
		cout << a[i].id << " ";
		i = path[i];
	}
	cout << endl;
}

int main() {
	_FAST;
	_cin(n);
	vector<mb> mbs(n);

	for (int i = 0; i < n; ++i){
		cin >> mbs[i].strength >> mbs[i].beauty;
		mbs[i].id = i + 1;
	}
	sort(mbs.begin(), mbs.end(), [](const mb &a, const mb &b){
		return a.strength != b.strength ? a.strength < b.strength : a.beauty > b.beauty;
	});
	printLIS(mbs);

	return 0;
}
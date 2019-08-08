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
//=============================================================================================

/**
** Comment **
**/

#define hash_value first
#define this_string second

ll lcs[110][110];
string space;

inline void solve(const vector<plls>& per1, vector<plls>& per2) {
	int m = per1.size(), n = per2.size();

	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == 0 || j == 0)
				lcs[i][j] = 0;
			else if (per1[i - 1].hash_value == per2[j - 1].hash_value)
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
}

void print(const vector<plls>& per1, vector<plls>& per2, int i, int j) {
	if (i > 0 && j > 0) {
		if (per1[i - 1].hash_value == per2[j - 1].hash_value) {
			print(per1, per2, i - 1, j - 1);
			cout << space << per1[i - 1].this_string;
			space = " ";
		}
		else if (lcs[i - 1][j] > lcs[i][j - 1]) print(per1, per2, i - 1, j);
		else print(per1, per2, i, j - 1);
	}
}

int main() {
	_FAST;
	string tmp;
	while (cin >> tmp) {
		space = "";
		vector<plls> per1, per2;
		hash<string> str_hash;

		do {
			ll hashValue = str_hash(tmp);
			per1.push_back({ hashValue, tmp });
		} while (cin >> tmp && tmp != "#");

		while (cin >> tmp && tmp != "#") {
			ll hashValue = str_hash(tmp);
			per2.push_back({ hashValue, tmp });
		}

		solve(per1, per2);
		print(per1, per2, per1.size(), per2.size());
		cout << endl;
	}

	return 0;
}
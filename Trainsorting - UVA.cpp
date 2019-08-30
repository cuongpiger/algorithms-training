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

//========================================================================================================================
#define pw(a) ((a) * (a))
#define vit vector<int>::iterator
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
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
typedef vector<vector<pii>> vvpii;
typedef vector<vector<vector<int>>> vvvint;
typedef vector<vector<vector<long long>>> vvvll;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
//========================================================================================================================

//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2451
/**
** Comment **
**/

int lis[2010], lds[2010], a[2010];

inline int LIS(int n) {
	int maxx = 0;

	for (int i = 0; i < n; ++i) {
		lis[i] = lds[i] = 1;

		for (int j = 0; j < i; ++j) {
			if (a[j] < a[i] && lis[j] + 1 > lis[i]) {
				lis[i] = lis[j] + 1;
			}

			if (a[j] > a[i] && lds[j] + 1 > lds[i]) {
				lds[i] = lds[j] + 1;
			}
		}

		maxx = max(maxx, lis[i] + lds[i] - 1);
	}

	return maxx;
}

int main() {
	FAST_IO;
	int tc, n; cin >> tc;

	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[n - i - 1];
		}

		cout << LIS(n) << endl;
	}
	
	return 0;
}

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

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1576
/**
 ** Comment **
 **/

int main() {
	_FAST;
	_cin(tc);

	for (int cs = 1; cs <= tc; ++cs) {
		int n, p, q, tmp, path[62510] = {};
		vint lis;
		cin >> n >> p >> q;
		++p, ++q;

		for (int i = 1; i <= p; ++i) {
			cin >> tmp;
			path[tmp] = i;
		}

		for (int i = 1; i <= q; ++i) {
			cin >> tmp;

			if (path[tmp]) {
				int pos = lower_bound(lis.begin(), lis.end(), path[tmp]) - lis.begin();
				if (lis.size() == pos) lis.push_back(path[tmp]);
				else lis[pos] = path[tmp];
			}
		}

		printf("Case %d: %d\n", cs, lis.size());
	}
	
	return 0;
}

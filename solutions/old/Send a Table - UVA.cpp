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

//=============================================================================================
#define pw(a) ((a) * (a))
#define _x first
#define _y second
#define vit vector<int>::iterator
#define _cin(X) int (X); cin >> X
const double pi = 3.14159265359;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a %b); }
inline double _distance(const pii &a, const pii &b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=============================================================================================
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1761
/**
** Comment **
https://imgur.com/gallery/Xt3okU5
** How to solve this problem **
- You need to draw a few cases with n = 5, 6, 7, ans so on, let open the image file from the link above:
	+ Here I call the red cells are the root cells (cells that will count to print to the screen)
	+ Blue cells are dependent cells that are generated from red cells (no need to count in output)
- Except for n = 1, then the remaining cases will be counted by countRedCellAtN_EqualTo[n] = countRedCellAtN_EqualTo[n - 1] + 
2*phi(n), you need multiply phi[n] by 2 becase phi[n] is just the number of red cells in the upper triangular matrix (consider the 
image file to understand)
**/

ll countRedCellAtN_EqualTo[50001];

inline ll phi(ll n) {
	ll res = n;
	for (ll i = 2; i*i <= n; ++i) {
		if (!(n%i)) {
			while (!(n%i)) {
				n /= i;
			}

			res = res / i * (i - 1);
		}
	}

	if (n > 1) res = res / n*(n - 1);
	return res;
}

inline void initializeTable() {
	countRedCellAtN_EqualTo[1] = 1;
	for (ll i = 2; i <= 50001; ++i) {
		countRedCellAtN_EqualTo[i] = countRedCellAtN_EqualTo[i - 1] + 2 * phi(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	initializeTable();
	ll n;

	while (cin >> n && n) {
		cout << countRedCellAtN_EqualTo[n] << endl;
	}

	return 0;
}

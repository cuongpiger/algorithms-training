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

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=347
/**
** Comment **
**/

inline vector<int> initializePrimes() {
	vector<bool> mark(1001, true);
	vector<int> primes;
	primes.push_back(1), primes.push_back(2);

	for (int i = 4; i <= 1000; i += 2) mark[i] = false;
	for (int i = 3; i <= 1000; i += 2) {
		if (mark[i]) {
			primes.push_back(i);

			for (int j = pw(i); j <= 1000; j += (i << 1)) mark[j] = false;
		}
	}

	return primes;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	vector<int> primes = initializePrimes();
	int n, c;

	while (cin >> n >> c) {
		vit lb = lower_bound(primes.begin(), primes.end(), n);
		int end_index = lb - primes.begin();
		end_index -= (end_index == primes.size() || primes[end_index] > n);

		cout << n << " " << c << ":";
		c = 2 * c - ((end_index + 1) & 1 != 0);
		int i = (end_index + 1 - c) / 2;
		if (i <= 0) {
			i = 0;
			c = end_index + 1;
		}

		for (int j = i; j < i + c; ++j) {
			cout << " " << primes[j];
		}

		cout << endl << endl;
	}

	return 0;
}

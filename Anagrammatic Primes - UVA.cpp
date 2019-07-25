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

/**
** Comment **
https://www.geeksforgeeks.org/check-number-permutable-prime/
**/

const int limit = 3165; // sqrt(1e7)
vector<bool> mark;

inline vector<int> initializePrimes() {
	vector<int> primes;
	primes.push_back(2);
	mark.resize(limit + 1, true);
	mark[0] = mark[1] = false;
	
	for (int i = 4; i <= limit; i += 2) {
		mark[i] = false;
	}
	for (int i = 3; i <= limit; i += 2) {
		if (mark[i]) {
			primes.push_back(i);
			for (int j = pw(i); j <= limit; j += (i << 1)) mark[j] = false;
		}
	}

	return primes;
}

inline bool checkPermutablePrime(int n) {
	int num[7]; // to store digits
	int pos = 0;

	while (n > 0) {
		num[pos++] = n % 10;
		n /= 10;
	}

	int sz = pos; // size of array
	bool flag = false;
	sort(num, num + sz);

	do {
		int tmp = 0;
		pos = 0;

		while (pos < sz) tmp = tmp * 10 + num[pos++];
		if (tmp < 3165 && !mark[tmp]) {
			flag = true;
			break;
		}
	} while (next_permutation(num, num + sz));

	// if flag is true, number is not permutable prime
	if (flag) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	vector<int> primes = initializePrimes();
	vector<int> permutablePrimes;
	for (int i = 0; i < primes.size(); ++i) {
		if (checkPermutablePrime(primes[i])) permutablePrimes.push_back(primes[i]);
	}

	int n;
	while (cin >> n && n) {
		int noDigits = 1 + log10(n*1.0);
		int res = 0;
		ll power10 = pow(10, 1.0*(noDigits));
		vit ub = upper_bound(permutablePrimes.begin(), permutablePrimes.end(), n);
		int index = ub - permutablePrimes.begin();

		if (index < permutablePrimes.size() && permutablePrimes[index] < power10) {
			res = permutablePrimes[index];
		}

		cout << res << endl;
	}

	return 0;
}
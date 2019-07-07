#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;

//=============================================================================================
const double pi = 3.14159265359;
#define p(a) ((a) * (a))
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
//=============================================================================================

/**
 ** Comment **
- Can find out more about the power of two on this page:
https://www.exploringbinary.com/ten-ways-to-check-if-an-integer-is-a-power-of-two-in-c/
https://imgur.com/gallery/rO0N0wf
 **/

bool isPowerOfTwo(int &x) {
	return (x && !(x & (x - 1)));
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int tc, n; cin >> tc;

	while (tc--) {
		cin >> n;
		vector<int> a(n);

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		if (n == 1) {
			if (isPowerOfTwo(a[0])) cout << "YES" << endl;
			else cout << "NO" << endl;

			continue;
		}

		int sumAllPowerOfTwo = 2147483647; /*This number can be much larger, but in Int type, 
		the largest number is 2147483647, so only 32 numbers are power of 2 in this limit*/
		// This is a number when adding all the numbers that are the power of two, it's a string
		// containing the whole bit 1
		// Can rewrite by the following way:
		/*
			int sumAllPowerOfTwo = 0;

			for (int i = 0; i < 31; ++i) {
				sum |= (1 << i);
				(or can also write like this: sum += (1 << i))
			}
		*/
		bool flag = 0;
		int minuend;

		for (int i = 0; i < 31; ++i) {
			minuend = sumAllPowerOfTwo;

			for (int j = 0; j < n; ++j) {
				// if it's a number that has form's power of two;
				if (a[j] & (1 << i)) minuend &= a[j];
				// if a[j] is a power of two, the variable 'minuend' becomes a number that is the power of two.
			}

			// if 'minuend' is a power of two
			if (isPowerOfTwo(minuend)) {
				flag = 1;
				break;
			}
		}

		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
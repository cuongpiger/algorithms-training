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
- Just take 2 numbers N and M and then convert them to binary strings. then multiply 2 binary strings
together as usual, you will understand the problem.
https://imgur.com/gallery/uoDBXqT?fbclid=IwAR2IhTuazcwZg5pHtUf9qChk0xBANLKsED51cXJPGRpfvwixjN8AT3qkMEo
 **/

int main() {
	int tc; cin >> tc;
	ll n, m;
	vector<ll> radiexs;

	while (tc--) {
		radiexs.clear();
		cin >> n >> m; //read N and M

		ll radiex = 0;

		while (m > 0) {
			if (m % 2) { // if m is an odd number;
				radiexs.push_back(radiex);
			}
			m >>= 1;
			++radiex;
		}

		cout << "(" << n << "<<" << radiexs[radiexs.size() - 1] << ")";
		for (int i = radiexs.size() - 2; i >= 0; --i) {
			cout << " + (" << n << "<<" << radiexs[i] << ")";
		}
		puts("");
	}

	return 0;
}
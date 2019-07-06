//https://textsaver.flap.tv/lists/2rtv
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <fstream>
#include <bitset>
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

int xorAtIndex[(int)1e5 + 5], countZeroAtIndex[(int)1e5 + 5];

int main() {
	int n, x, q, l, r;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> x;
		xorAtIndex[i] = xorAtIndex[i - 1] ^ x;
		countZeroAtIndex[i] = countZeroAtIndex[i - 1];

		if (!x) ++countZeroAtIndex[i];
	}

	cin >> q;
	while (q--) {
		cin >> l >> r;
		cout << (xorAtIndex[r] ^ xorAtIndex[l - 1]) << " " << (countZeroAtIndex[r] - countZeroAtIndex[l - 1]) << endl;
	}
	
	return 0;
}

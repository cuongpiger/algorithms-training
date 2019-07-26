#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
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
 **/

int s[13], res[6], k;

void solve(int c, int j) {
	if (c == 6) {
		printf("%d", res[0]);
		for (int i = 1; i < 6; ++i)
			printf(" %d", res[i]);
		puts("");

		return;
	}

	for (; j < k; ++j) {
		res[c] = s[j];
		solve(c + 1, j + 1);
	}
}

int main() {
	int br = 0;

	while (scanf("%d", &k) == 1 && k) {
		if (br) {
			puts("");
		}
		br = 1;

		for (int i = 0; i < k; ++i) 
			scanf("%d", &s[i]);

		solve(0, 0);
	}

	return 0;
}

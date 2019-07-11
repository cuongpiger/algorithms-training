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

int n, h;

inline bool shouldSwap(string &s, int &start, int &end) {
	for (int i = start; i < end; ++i)
		if (s[i] == s[end]) return 0;
	return 1;
}

void solve(string s, int l, int r) {
	if (l >= r) {
		puts(s.c_str());
		return;
	}

	for (int i = l; i < r; ++i) {
		bool check = shouldSwap(s, l, i);

		if (check) {
			swap(s[l], s[i]);
			solve(s, l + 1, r);
			swap(s[l], s[i]);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int tc; scanf("%d", &tc);

	while (tc--) {
		scanf("%d%d", &n, &h);
		string s(n, '1');
		for (int i = 0; i < n - h; ++i) s[i] = '0';
		solve(s, 0, n);
	
		if (tc) puts("");
	}

	return 0;
}

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

//https://www.hackerrank.com/challenges/sansa-and-xor/problem
/**
 ** Comment **
 https://www.youtube.com/watch?v=knHJM_JG2Po
 **/

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int tc, n, x, res; cin >> tc;

	while (tc--) {
		res = 0;
		cin >> n;

		for (int i = 0; i < n; ++i) {
			cin >> x;

			if ((i + 1 )% 2) {
				res ^= x;
			}
		}

		if (n % 2) cout << res << endl;
		else cout << 0 << endl;
	}

	return 0;
}

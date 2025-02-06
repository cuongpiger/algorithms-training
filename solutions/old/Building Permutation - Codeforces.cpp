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
using namespace std;

//=============================================================================================
#define pw(a) ((a) * (a))
#define x first
#define y second
const double pi = 3.14159265359;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
//=============================================================================================

//https://codeforces.com/problemset/problem/285/C
/**
 ** Comment **
 **/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, res = 0; cin >> n;
	vector<ll> p(n, 0);

	for (ll i = 0; i < n; ++i){
		cin >> p[i];
	}
	sort(p.begin(), p.end());

	for (ll i = 0; i < n; ++i){
		res += llabs((i + 1) - p[i]);
	}

	cout << res << endl;

	return 0;
}

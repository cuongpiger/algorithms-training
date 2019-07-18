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

/**
 ** Comment **
 **/

#define amount first
#define position second

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, tmp, res;

	while (cin >> n, n){
		vector<p2ll> sell, buy;
		res = 0;

		for (ll i = 0; i < n; ++i){
			cin >> tmp;

			if (tmp < 0){
				buy.push_back({ tmp*-1, i });
			}
			else{
				sell.push_back({ tmp, i });
			}
		}

		ll i = 0, j = 0;

		while (i < buy.size() && j < sell.size()){
			ll _min = min(buy[i].amount, sell[j].amount);
			res += _min * abs(buy[i].position - sell[j].position);
			buy[i].amount -= _min, sell[j].amount -= _min;
			i += (!buy[i].amount), j += (!sell[j].amount);
		}

		cout << res << endl;
	}

	return 0;
}
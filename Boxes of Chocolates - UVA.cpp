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
#define x first
#define y second
#define vit vector<int>::iterator
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

#define _cin(X) int (X); cin >> X;
int _gcd(int a, int b){ return !b ? a : _gcd(b, a %b);}

/**
** Comment **
**/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	_cin(tc);
	while (tc--){
		_cin(n);
		_cin(b);
		int sum = 0;

		while (b--){
			_cin(k);
			int multy = 1;

			while (k--){
				_cin(box);
				multy *= box;
				multy %= n;
			}
			sum += multy;
			sum %= n;
		}

		cout << sum << endl;
	}
	
	return 0;
}
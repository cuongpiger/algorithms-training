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

/*HOW TO SOLVE THIS PROBLEM
- The first: the boys and girls of Drazil are numbered from 0 to n - 1 and m - 1, that means at the index ith of
person ith, So, this person can only be invited on dates that are multiples of person's index ith

***** SOLVE IT *****
Step 1:
	- Need to find the greatest common divisor of n and m, because the boys and girls can only be invited 
on dates equal to i % n and i % m, therefore boys and girls have congruence relation each other which equal to
a number from 0 to less than gcd(n, m) will be happy if this group has at least 1 happy person
Step 2:
	- Create an bool array from 0 to less than gcd(n, m)
Step 3: 
	- With every happy boy or girl, at bool array's index equal to their index % gcd(n, m) will become true
Step 4:
	- If it's have a bool array's index which equal to false, print "NO" ortherwise don't have any index which equal to 
false, print "YES"
	
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	_cin(n); 
	_cin(m);
	int gcd = _gcd(n, m);
	int cnt = 0;
	vector<bool> happy(gcd, false);

	_cin(noBoys);
	for (int i = 0; i < noBoys; ++i){
		_cin(p);
		
		if (!happy[p%gcd]){
			cnt++;
			happy[p%gcd] = true;
		}
	}

	_cin(noGirls);
	for (int i = 0; i < noGirls; ++i){
		_cin(p);

		if (!happy[p%gcd]){
			cnt++;
			happy[p%gcd] = true;
		}
	}

	cout << (cnt == gcd ? "Yes" : "No");
	
	return 0;
}
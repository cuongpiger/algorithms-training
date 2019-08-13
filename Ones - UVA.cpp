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
#define _cin(X) int (X); cin >> X
const double pi = 3.14159265359;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
int _gcd(int a, int b){ return !b ? a : _gcd(b, a %b); }
inline double _distance(const pii &a, const pii &b){ return sqrt(pw((double)(a.x - b.x)) + pw((double)(a.y - b.y))); }
//=============================================================================================

//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1068
/**
** Comment **
https://www.mathblog.dk/uva-10127-ones/
**/

int n;
inline int modulo(){
	int cnt = 1;
	ll dividend = 1;

	while (dividend % n){
		dividend = (dividend * 10 + 1) % n;
		++cnt;
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	while (cin >> n){
		cout << modulo() << endl;
	}

	return 0;
}

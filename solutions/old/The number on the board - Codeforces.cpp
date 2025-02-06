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

//https://codeforces.com/problemset/problem/835/B
/**
 ** Comment **
 **/

int k, sum = 0, res = 0;
string n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> k >> n;
	
	for (int i = 0; i < n.length(); ++i){
		sum += (n[i] - '0');
	}

	sort(n.begin(), n.end());

	for (int i = 0; i < n.length(); ++i){
		if (sum < k){
			++res;
			sum += (9 - (n[i] - '0'));
		}
		else{
			break;
		}
	}
	
	cout << res << endl;

	return 0;
}

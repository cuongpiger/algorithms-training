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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k, tmp, sum = 0;
	priority_queue <int, vector<int>, greater<int>> pq;

	cin >> n >> k;

	while (n--){
		cin >> tmp;
		sum += tmp;
		pq.push(tmp);
	}

	while (k--){
		tmp = pq.top();
		sum -= tmp;
		sum += (tmp * -1);
		pq.pop();
		pq.push(tmp * -1);
	}

	cout << sum << endl;

	return 0;
}
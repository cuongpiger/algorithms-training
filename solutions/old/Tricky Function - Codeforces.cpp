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
#define x(a) (a.first)
#define y(a) (a.second)
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

//https://codeforces.com/problemset/problem/429/D
/**
 ** Comment **
- If a number is a smallest number, the its square root will be the smallest number
 **/

const double INF = 1e10;
int n;
vector<pdd> points; // to store x and y coordinates

inline double calcDistance(pdd &p1, pdd &p2){
	return sqrt(pw(x(p1) - x(p2)) + pw(y(p1) - y(p2)));
}

inline pair<pdd, pdd> bruteForce(int &l, int &r){
	double min_dist = INF;
	pdd reP1 = { INF, INF }, reP2 = {-INF, -INF};

	for (int i = l; i < r; ++i){
		for (int j = i + 1; j < r; ++j){

			if (calcDistance(points[i], points[j]) < min_dist){
				min_dist = calcDistance(points[i], points[j]);
				reP1 = points[i], reP2 = points[j];
			}
		}
	}

	return pair < pdd, pdd > {reP1, reP2};
}

inline pair<pdd, pdd> stripClosest(vector<pdd> &strip ,pair<pdd, pdd> &min_dist){
	sort(strip.begin(), strip.end(), [](const pdd &a, const pdd &b){
		return y(a) < y(b);
	});
	pair<pdd, pdd> minDist = min_dist;

	for (int i = 0; i < strip.size(); ++i){
		for (int j = i + 1; j < strip.size() && (y(strip[j]) - y(strip[i])) < (calcDistance(minDist.first, minDist.second)); ++j){
			if (calcDistance(strip[i], strip[j]) < calcDistance(minDist.first, minDist.second)){
				minDist = { strip[i], strip[j] };
			}
		}
	}

	return minDist;
}

pair<pdd, pdd> minimalDistance(int l, int r){
	if (r - l <= 3) return bruteForce(l, r);

	int m = l + (r - l) / 2;
	pdd midPoint = points[m];
	pair<pdd, pdd> dist_left = minimalDistance(l, m);
	pair<pdd, pdd> dist_right = minimalDistance(m + 1, r);
	pair<pdd, pdd> min_dist = dist_left;
	vector<pdd> strip;

	if (calcDistance(dist_right.first, dist_right.second) < calcDistance(dist_left.first, dist_left.second)) min_dist = dist_right;
	for (int i = l; i < r; ++i){
		if (fabs(x(points[i]) - x(midPoint)) < calcDistance(min_dist.first, min_dist.second)){
			strip.push_back(points[i]);
		}
	}
	pair<pdd, pdd> rePoint = stripClosest(strip, min_dist);

	return (calcDistance(min_dist.first, min_dist.second) < calcDistance(rePoint.first, rePoint.second)) ? min_dist : rePoint;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	points.resize(n), x(points[0]) = 1;
	cin >> y(points[0]);

	for (int i = 1; i < n; ++i){
		cin >> y(points[i]);
		y(points[i]) += y(points[i - 1]);
		x(points[i]) = i + 1;
	}

	pair<pdd, pdd> res = minimalDistance(0, n);
	cout << fixed << setprecision(0) << pw(x(res.first) - x(res.second)) + pw(y(res.first) - y(res.second)) << endl;
	
	return 0;
}

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

/**
 ** Comment **
 **/
const double INF = 1e5;
int n;
vector<pdd> points;

inline double calcDistance(pdd &p1, pdd &p2){
	return sqrt(pw(x(p1) - x(p2)) + pw(y(p1) - y(p2)));
}

inline double bruteForce(vector<pdd> &pointSet, int &left, int &right){
	double min_dist = INF;

	for (int i = left; i < right; ++i){
		for (int j = i + 1; j < right; ++j){
			min_dist = min(min_dist, calcDistance(pointSet[i], pointSet[j]));
		}
	}

	return min_dist;
}

inline double stripClosest(vector<pdd> &strip, double &min_dist){
	sort(strip.begin(), strip.end(), [](const pdd &left, const pdd &right){
		return y(left) < y(right);
	});
	double minDist = min_dist;

	for (int i = 0; i < strip.size(); ++i){
		for (int j = i + 1; j < strip.size() && (y(strip[j]) - y(strip[i])) < minDist; ++j){
			if (calcDistance(strip[i], strip[j]) < minDist){
				minDist = calcDistance(strip[i], strip[j]);
			}
		}
	}

	return minDist;
}

double minimalDistance(int left, int right){
	if (right - left <= 3){
		return bruteForce(points, left, right);
	}

	int mid = left + (right - left) / 2;
	pdd midPoint = points[mid];
	double dist_left = minimalDistance(left, mid);
	double dist_right = minimalDistance(mid + 1, right);
	double min_dist = min(dist_left, dist_right);
	vector<pdd> strip;

	for (int i = left; i < right; ++i){
		if (fabs(x(points[i]) - x(midPoint)) < min_dist){
			strip.push_back(points[i]);
		}
	}

	return min(min_dist, stripClosest(strip, min_dist));
}

int main() {
	/*ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);*/
	while (scanf("%d", &n) == 1 && n){
		pdd is;
		points.clear();

		for (int i = 0; i < n; ++i){
			cin >> x(is) >> y(is);
			points.push_back(is);
		}

		sort(points.begin(), points.end());
		double res = minimalDistance(0, n);

		if (res < 1e4)
			cout << fixed << setprecision(4) << res << endl;
		else
			cout << "INFINITY" << endl;
	}

	return 0;
}
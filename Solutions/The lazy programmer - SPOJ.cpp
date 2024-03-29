#pragma warning(disable:4996)
#include <iostream>
#include <cstdint>
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
#include <unordered_set>
#include <unordered_map>
using namespace std;

//==========================================================================================================================
#define pw(a) ((a) * (a))
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define dqit deque<int>::iterator
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define sortRev greater<int>()
const double pi = 3.14159265359;
const long long mod = 1e9 + 7;
typedef uint64_t uit;
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<double, int> pdi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
typedef pair<ll, string> plls;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pdi> vpdi;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<long long>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<vector<int>>> vvvi;
typedef deque<int> dqi;
typedef queue<int> qi;
typedef queue<pii> qpii;
int GCD(int a, int b) { return !b ? a : GCD(b, a % b); }
inline double DIST(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
inline int DEC(char x) { return (int)(x - '0'); }
//==========================================================================================================================

//https://www.spoj.com/problems/LAZYPROG/
/**
** Comment **
- Step 1:
	+ Create the structure Job to store the attribute of input data
	+ Create the jobs array and it should be sorted by attribute d, because the larger job's deadline is more
greater, so it should be worked at the last
	+ And then, we will create a max-heap of job, it would be sorted by the job's attribute a, so how is the attribute a,
, so the cost that director need to pay for programmer it will be calculate is:
<faster time solved = (b - a*money need pay more)>, so can see that if the attribute a is more greater, the money which
director need to pay more for programmer will be decreased
	+ Create a sumTime to add the attribute b when programmer readied to work the current job.
	+ Create a sumCost to sum money that director need to pay more for the director
**/

typedef struct {
	int a, b, d;
} Job;

struct option {
	bool operator() (const Job& a, const Job& b) {
		return a.a < b.a;
	}
};

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	int tc, n;
	vector<Job> jobs(100010);
	cin >> tc;

	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> jobs[i].a >> jobs[i].b >> jobs[i].d;
		}

		sort(jobs.begin(), jobs.begin() + n, [](const Job& a, const Job& b) {return a.d < b.d; });
		priority_queue < Job, vector<Job>, option> maxHeap;
		double sumCost = 0;
		int sumTime = 0;

		for (int i = 0; i < n; ++i) {
			maxHeap.push(jobs[i]);
			sumTime += jobs[i].b;

			while (sumTime > jobs[i].d) { 
				Job top = maxHeap.top();
				maxHeap.pop();

				if (top.b > sumTime - jobs[i].d) {
					sumCost += ((sumTime - jobs[i].d) * 1.0 / top.a);
					top.b -= (sumTime - jobs[i].d);
					maxHeap.push(top);
					sumTime = jobs[i].d;
				}
				else {
					sumCost += (top.b * 1.0 / top.a);
					sumTime -= top.b;
					top.b = 0;
				}
			}
		}

		cout << fixed << setprecision(2) << sumCost << endl;
	}

	return 0;
}
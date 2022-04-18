// O(n*log(n))

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

int main() {
    FAST_IO;
    // FILE_IO;

    int n;
    double w, cups[200010];

    cin >> n >> w;
    for (int i = 0; i < n*2; ++i) cin >> cups[i];

    sort(cups, cups + (sizeof(cups)/sizeof(cups[0])) / 200010 * 2*n);

    double girl = cups[0], boy = cups[n] / 2;
    double d = w / (3 * n);
    double res = min(d, min(girl, boy));

    cout << fixed << setprecision(6) << res * 3 * n;

    return 0;
}
// O(n*log(n))

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

typedef long long ll;

int main() {
    FAST_IO;
    // FILE_IO;

    int n, x;
    ll c[100010], res = 0;

    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> c[i];

    sort(c, c + (sizeof(c)/sizeof(c[0])) / 100010 * n);
    
    for (int i = 0; i < n; ++i) 
        res += (max(1, x--) * c[i]);

    cout << res;

    return 0;
}
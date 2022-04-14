// O(n)

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)


int main() {
    FAST_IO;
    // FILE_IO;

    int n, choco[100010];
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> choco[i];
    }

    int i = -1, j = n, alice = 0, bob = 0;
    while (j - i > 1) {
        if (alice <= bob) alice += choco[++i];
        else bob += choco[--j];
    }

    cout << i + 1 << " " << n - j;

    return 0;
}
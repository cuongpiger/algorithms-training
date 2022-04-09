#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

int n, m;
char board[110][110];
inline bool valid(int x, int y) {
    for (int i = 0; i < m; ++i) {
        if (i != y && board[x][i] == board[x][y]) {
            return false;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i != x && board[i][y] == board[x][y]) {
            return false;
        }
    }

    return true;
}

int main() {
    FAST_IO;
    // FILE_IO;

    string res = "";

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (valid(i, j)) {
                res += board[i][j];
            }
        }
    }

    cout << res;

    return 0;
}
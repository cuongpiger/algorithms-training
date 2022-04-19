// O(n)

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <iomanip>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

inline int convert(char &c) {
    if (c == 'C') return 12;
    if (c == 'H') return 1;
    if (c == 'O') return 16;
    if (c == '(') return 0;
    if (c == ')') return -1;
    return (int) (c - '0');
}

int main() {
    FAST_IO;
    // FILE_IO;

    string fo; cin >> fo;
    stack<int> s;
    int res = 0;

    for (int c, sm, top, i = 0; i < fo.size(); ++i) {
        c = convert(fo[i]);
        if (c >= 2 && c <= 9) {
            top = s.top();
            s.pop();
            s.push(top * c);
        } else if (c == -1) {
            sm = 0;
            while (true) {
                top = s.top();
                s.pop();
                sm += top;

                if (top == 0) {
                    s.push(sm);
                    break;
                }
            }
        } else {
            s.push(c);
        }
    }

    while (!s.empty()) {
        res += s.top();
        s.pop();
    }

    cout << res;

    return 0;
}
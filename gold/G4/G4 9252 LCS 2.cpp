/*
#include <iostream>
#include <stack>
using namespace std;

string s;
string s2;
int LCS[1001][1001];

void input();
void solve();
int main() {
    ios_base::sync_with_stdio(false);
    input();
    solve();

    return 0;
}

void input() {
    cin.tie(NULL);
    cin >> s >> s2;
}

void solve() {
    cout.tie(NULL);

    int length = 0;
    pair<int, int> idx;
    for(int i = 1; i <= s.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            if(s[i - 1] == s2[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);

            if(length <= LCS[i][j]) {
                length = LCS[i][j];
                idx = {i, j};
            }
        }
    }
    cout << length << "\n";

    int i = idx.first;
    int j = idx.second;
    int cur = length;
    stack<char> result;
    while(LCS[i][j] != 0) {
        if(LCS[i - 1][j] == cur)
            i--;
        else if (LCS[i][j - 1] == cur)
            j--;

        else {
            result.push(s[i - 1]);
            i--;
            j--;
            cur--;
        }
    }

    while(!result.empty()) {
        cout << result.top();
        result.pop();
    }
}*/

/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, lastDice;
vector<int> v;

void input() {
    cin >> n;

    for(int i = 0; i <= n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    cin >> lastDice;
}

bool safeCheck(int start, int end, vector<int> &notSafeZone) {
    if(v[start] == 1 || v[end] == 1) {
        return 0;
    }

    for(int i = 0; i < notSafeZone.size(); i++) {
        if(v[notSafeZone[i]] == 1) {
            return 0;
        }
    }

    return 1;
}

void solve() {
    string result = "NO";

    vector<int> notSafeZone;
    for(int i = 0; i <= n; i++) {
        if(v[i] == 1) {
            notSafeZone.push_back(i);
        }
    }

    for(int i = 0; i <= n; i++) {
        if(i + lastDice < n + 1) {
            if(v[i] > 0) {
                v[i]--;
                v[i + lastDice]++;

                if (safeCheck(i, i + lastDice, notSafeZone)) {
                    result = "YES";
                    int start = i;
                    int end = i + lastDice;

                    cout << result << '\n' << start << " " << end;
                    exit(0);
                } else {
                    v[i]++;
                    v[i + lastDice]--;
                }
            }
        }
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}
*/

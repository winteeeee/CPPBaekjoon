/*
#include <iostream>
#include <vector>
using namespace std;

int n;
int answer = -1;
vector<bool> cur, target;

void input() {
    cin >> n;
    char temp;

    cin.ignore();
    for(int i = 0; i < n; i++) {
        cin.get(temp);

        if(temp == '0') {
            cur.push_back(0);
        } else {
            cur.push_back(1);
        }
    }

    cin.ignore();
    for(int i = 0; i < n; i++) {
        cin.get(temp);

        if(temp == '0') {
            target.push_back(0);
        } else {
            target.push_back(1);
        }
    }
}

void convertSwitch(int pos) {
    if (pos == 0) {
        cur[pos] = !cur[pos];
        cur[pos + 1] = !cur[pos + 1];
    } else if (pos == (n - 1)) {
        cur[pos] = !cur[pos];
        cur[pos - 1] = !cur[pos - 1];
    } else {
        cur[pos - 1] = !cur[pos - 1];
        cur[pos] = !cur[pos];
        cur[pos + 1] = !cur[pos + 1];
    }
}

int counting() {
    int result = 0;

    for(int i = 1; i < n; i++) {
        if(cur[i - 1] != target[i - 1]) {
            convertSwitch(i);
            result++;
        }
    }

    return result;
}

bool isEqual() {
    for(int i = 0; i < n; i++) {
        if(cur[i] != target[i]) {
            return false;
        }
    }

    return true;
}

void solve() {
    vector<bool> temp = cur;
    int curCount;

    curCount = counting();
    if(isEqual()) {
        answer = curCount;
    }

    cur = temp;
    convertSwitch(0);
    curCount = counting() + 1;
    if(isEqual()) {
        if(answer != -1) {
            answer = min(answer, curCount);
        }

        else {
            answer = curCount;
        }
    }

    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}*/

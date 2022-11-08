/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count = 0;
vector<int> idx;
vector<int> getPi(const string &s);
void solve(const string &s, const string &sub, const vector<int> &pi);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, sub;
    getline(cin , s);
    getline(cin, sub);
    vector<int> pi = getPi(sub);
    solve(s, sub, pi);

    cout << count << "\n";
    for(int i = 0; i < idx.size(); i++) {
        cout << idx[i] << " ";
    }
    return 0;
}

vector<int> getPi(const string &s) {
    int j = 0;
    vector<int> pi(s.length(), 0);
    pi.push_back(0);

    for(int i = 1; i < s.length(); i++) {
        while(j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if(s[i] == s[j]) {
            pi[i] = ++j;
        }
    }

    return pi;
}

void solve(const string &s, const string &sub, const vector<int> &pi) {
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
        while (j > 0 && s[i] != sub[j]) {
            j = pi[j - 1];
        }

        if (s[i] == sub[j]) {
            if (j < sub.length() - 1) {
                j++;
            }

            else {
                count++;
                idx.push_back(i - j + 1);
                j = pi[j];
            }
        }
    }
}*/

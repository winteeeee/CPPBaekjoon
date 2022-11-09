/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> s;
vector<char> alphaVector;
int result = 0;
void input();
bool comp(const string &a, const string &b);
int countAlpha();
void solve();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        s.push_back(temp);
    }
}

bool comp(const string &a, const string &b) {
    return a.size() > b.size();
}

int countAlpha() {
    int count = 0;
    bool alpha[26] {false};

    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j < s[i].size(); j++) {
            if(!alpha[s[i][j] - 'A']) {
                alphaVector.push_back(s[i][j]);
                alpha[s[i][j] - 'A'] = true;
                count++;
            }
        }
    }

    return count;
}

void solve() {
    sort(s.begin(), s.end(), comp);
    int alphabetCount = countAlpha();
    vector<int> p(alphabetCount);
    for(int i = 0; i < p.size(); i++)
        p[i] = 9 - i;

    vector<int> map(26, 0);
    do {
        int sum = 0;
        for(int i = 0; i < alphabetCount; i++)
            map[alphaVector[i] - 'A'] = p[i];

        for(int i = 0; i < s.size(); i++) {
            int temp = 0;

            for(int j = 0; j < s[i].size(); j++)
                temp = temp * 10 + map[s[i][j] - 'A'];

            sum += temp;
        }

        if(result < sum)
            result = sum;
    } while(prev_permutation(p.begin(), p.end()));

    cout << result;
}*/

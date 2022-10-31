/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(const vector<char> &inequality, const vector<int> &cur) {
    for(int i = 0; i < inequality.size(); i++) {
        if(inequality[i] == '<' && cur[i] > cur[i + 1])
            return false;
        if(inequality[i] == '>' && cur[i] < cur[i + 1])
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;
    vector<char> inequality;
    for(int i = 0; i < k; i++) {
        char temp;
        cin >> temp;
        inequality.push_back(temp);
    }

    vector<int> min, max;
    for(int i = 0; i <= k; i++) {
        min.push_back(i);
        max.push_back(9 - i);
    }

    do {
        if(check(inequality, min))
            break;
    } while(next_permutation(min.begin(), min.end()));

    do {
        if(check(inequality, max))
            break;
    } while(prev_permutation(max.begin(), max.end()));

    string resultMin, resultMax;
    for(int i = 0; i <= k; i++) {
        resultMin += to_string(min[i]);
        resultMax += to_string(max[i]);
    }

    cout << resultMax << "\n" << resultMin;
    return 0;
}
*/

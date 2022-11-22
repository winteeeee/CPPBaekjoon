/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<vector<int>> table;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<int> p(n, 0);
    for(int i = 0; i < n; i++) {
        p[i] = i;
        vector<int> temp(n, 0);
        for(int j = 0; j < n; j++) {
            cin >> temp[j];
        }
        table.push_back(temp);
    }

    int result = INT_MAX;
    vector<int> combination;
    for(int i = 0; i < n / 2; i++) {
        combination.push_back(1);
    }
    for(int i = n / 2; i < n; i++) {
        combination.push_back(0);
    }
    sort(combination.begin(), combination.end());

    do {
        int start = 0;
        int link = 0;

        vector<int> startIdx;
        vector<int> linkIdx;
        for(int i = 0; i < n; i++) {
            if(combination[i] == 1)
                startIdx.push_back(p[i]);
            else
                linkIdx.push_back(p[i]);
        }


        for(int i = 0; i < n / 2; i++) {
            for(int j = i + 1; j < n / 2; j++) {
                start += (table[startIdx[i]][startIdx[j]] + table[startIdx[j]][startIdx[i]]);
                link += (table[linkIdx[i]][linkIdx[j]] + table[linkIdx[j]][linkIdx[i]]);
            }
        }

        int temp = abs(start - link);
        if(result > temp) {
            result = temp;
        }
    } while(next_permutation(combination.begin(), combination.end()));

    cout << result;
    return 0;
}*/

/*
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> con;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int e = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        e += temp;
        con.push_back(temp);
    }
    e /= n;

    int count = 0;
    int pickUp = 0;
    for(int i = 0; i < n; i++) {
        if(con[i] > (e + 1)) {
            pickUp += (con[i] - (e + 1));
            con[i] = (e + 1);
        }
    }

    for(int i = 0; i < n; i++) {
        if(con[i] < e) {
            count += (e - con[i]);
        }
    }

    if(pickUp > count) {
        count += (pickUp - count);
    }

    cout << count;
    return 0;
}*/

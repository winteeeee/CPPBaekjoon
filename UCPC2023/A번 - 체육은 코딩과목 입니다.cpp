/*
#include <iostream>
using namespace std;

int t[10];
char cur = 'N';

void one() {
    if (cur == 'N') {
        cur = 'E';
    } else if (cur == 'E') {
        cur = 'S';
    } else if (cur == 'S') {
        cur = 'W';
    } else {
        cur = 'N';
    }
}

void two() {
    if (cur == 'N') {
        cur = 'S';
    } else if (cur == 'E') {
        cur = 'W';
    } else if (cur == 'S') {
        cur = 'N';
    } else {
        cur = 'E';
    }
}

void three() {
    if (cur == 'N') {
        cur = 'W';
    } else if (cur == 'E') {
        cur = 'N';
    } else if (cur == 'S') {
        cur = 'E';
    } else {
        cur = 'S';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 10; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < 10; i++) {
        if (t[i] == 1) {
            one();
        } else if (t[i] == 2) {
            two();
        } else {
            three();
        }
    }

    cout << cur;
}*/

/*
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int p, q, c1, c2;
vector<int> px;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p >> q;
    cin >> c1 >> c2;
    priority_queue<int, vector<int>, greater<int>> h;
    for(int i = 0; i < p; i++) {
        int temp;
        cin >> temp;
        px.push_back(temp);
    }
    sort(px.begin(), px.end());

    for(int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        int lower = lower_bound(px.begin(), px.end(), temp) - px.begin();

        if(lower == px.size())  //못찾았는데 범위 밖
            h.push(abs(px[lower - 1] - temp));
        else if(px[lower] == temp)    //찾음
            h.push(0);
        else {  //못찾았는데 범위 안
            if(lower != 0) {
                if (abs(px[lower] - temp) > abs(px[lower - 1] - temp))
                    h.push(abs(px[lower - 1] - temp));
                else if(abs(px[lower] - temp) < abs(px[lower - 1] - temp))
                    h.push(abs(px[lower] - temp));
                else {
                    h.push(abs(px[lower - 1] - temp));
                    h.push(abs(px[lower] - temp));
                }
            }

            else {
                h.push(abs(px[lower] - temp));
            }
        }
    }

    int minDistance = h.top();
    h.pop();
    int count = 1;
    while(!h.empty()) {
        if(h.top() == minDistance) {
            count++;
            h.pop();
        }

        else
            break;
    }

    cout << minDistance + abs(c1 - c2) << " " << count;
    return 0;
}*/

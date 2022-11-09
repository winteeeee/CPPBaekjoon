/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> numbers(n);
    for(int i = 0; i < n; i++)
        cin >> numbers[i];

    vector<int> operators(4);
    for(int i = 0; i < 4; i++)
        cin >> operators[i];

    vector<int> p;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < operators[i]; j++) {
            p.push_back(i);
        }
    }

    int max = INT_MIN;
    int min = INT_MAX;
    do {
        int temp = numbers[0];

        for(int i = 0; i < n - 1; i++) {
            if(p[i] == 0)
                temp += numbers[i + 1];
            else if(p[i] == 1)
                temp -= numbers[i + 1];
            else if(p[i] == 2)
                temp *= numbers[i + 1];
            else
                temp /= numbers[i + 1];
        }

        if(temp > max)
            max = temp;
        if(temp < min)
            min = temp;
    } while(next_permutation(p.begin(), p.end()));

    cout << max << "\n" << min;
    return 0;
}
*/

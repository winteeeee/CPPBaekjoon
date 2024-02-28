/*
#include <iostream>
#include <climits>
using namespace std;

int sequence[100000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    for(int i = 0; i < n; i++)
        cin >> sequence[i];

    int length = -1;
    int start = 0;
    int end;
    int prefixSum = 0;
    for(int i = 0; i < n; i++) {
        prefixSum += sequence[i];

        if(prefixSum >= s) {
            end = i;
            length = i + 1;
            break;
        }
    }

    if(length == -1)
        cout << "0";

    else {
        int minLength = INT_MAX;
        while (end < n) {
            while (prefixSum - sequence[start] >= s) {
                prefixSum -= sequence[start++];
                length--;
            }

            if(length < minLength)
                minLength = length;

            while(end < n) {
                prefixSum += sequence[++end];
                length++;

                if(prefixSum > s)
                    break;
            }
        }

        cout << minLength;
    }

    return 0;
}*/

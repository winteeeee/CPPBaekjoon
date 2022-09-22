/*
#include <iostream>
using namespace std;

int count;
void DFS(int cur, bool visited[], int student[], bool end[]);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int l = 0; l < t; l++) {
        int student[100001];
        bool visited[100001] = {false};
        bool end[100001] = {false};
        count = 0;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> student[i];
        }

        for(int i = 1; i <= n; i++) {
            if(!visited[i])
                DFS(i, visited, student, end);
        }

        cout << n - count << "\n";
    }

    return 0;
}

void DFS(int cur, bool visited[], int student[], bool end[]) {
    visited[cur] = true;

    if(!visited[student[cur]]) {
        DFS(student[cur], visited, student, end);
    }

    else if(!end[student[cur]]) {
        for(int i = student[cur]; i != cur; i = student[i])
            count++;
        count++;
    }

    end[cur] = true;
}*/

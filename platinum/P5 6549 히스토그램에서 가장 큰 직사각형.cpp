#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Rectangle {
public:
    Rectangle(int h, int w) {
        height = h;
        width = w;
        area = h * w;
    }
    int height;
    int width;
    int area;
};

int n;
vector<Rectangle> rec;
bool input(int &n);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(input(n)) {
        stack<Rectangle> s;
        int first;
        cin >> first;
        Rectangle firstRec = Rectangle(first, 1);
        rec.push_back(firstRec);

        for(int i = 1; i < n; i++) {
            int h;
            cin >> h;
            Rectangle cur = Rectangle(h, 1);

            if (rec[i - 1].height < cur.height) {

            }

            else {

            }

        }
    }

    return 0;
}

bool input(int &n) {
    cin >> n;
    return n;
}
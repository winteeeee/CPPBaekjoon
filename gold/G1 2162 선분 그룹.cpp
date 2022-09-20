#include <iostream>
#include <vector>
using namespace std;

class Segment {
private:
    pair<int, int> point1;
    pair<int, int> point2;

public:
    Segment(int x1, int y1, int x2, int y2);
    pair<int, int> getPoint1();
    pair<int, int> getPoint2();
};

Segment::Segment(int x1, int y1, int x2, int y2) {
    point1 = {x1, y1};
    point2 = {x2, y2};
}

pair<int, int> Segment::getPoint1() {
    return point1;
}

pair<int, int> Segment::getPoint2() {
    return point2;
}

int set[3000];
int height[3000];
long long ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c);
bool isCross(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d);
void setUnion(int a, int b);
int setFind(int a);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        set[i] = i;
        height[i] = 1;
    }

    vector<Segment> segments;
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segments.push_back(Segment(x1, y1, x2, y2));
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            Segment seg1 = segments[i];
            Segment seg2 = segments[j];

            if(isCross(seg1.getPoint1(), seg1.getPoint2(), seg2.getPoint1(), seg2.getPoint2())) {
                setUnion(i, j);
            }
        }
    }

    int numberOfGroup = 0;
    int largestGroup = 0;
    for(int i = 0; i < n; i++) {
        if(set[i] == i) {
            numberOfGroup++;

            if(largestGroup < height[i])
                largestGroup = height[i];
        }
    }

    cout << numberOfGroup << "\n" << largestGroup;
    return 0;
}

long long ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int val = (a.first * b.second) + (b.first * c.second) + (c.first * a.second) - ((a.first * c.second) + (b.first * a.second) + (c.first * b.second));

    if(val < 0)
        return -1;

    else if(val > 0)
        return 1;

    else
        return 0;
}

bool isCross(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
    int seg1 = ccw(a, b, c) * ccw(a, b, d);
    int seg2 = ccw(c, d, a) * ccw(c, d, b);

    if(seg1 <= 0 && seg2 <= 0) {
        if ((a.first > c.first && a.first > d.first && b.first > c.first && b.first > d.first) ||
            (c.first > a.first && c.first > b.first && d.first > a.first && d.first > b.first)) return false;
        else if ((a.second > c.second && a.second > d.second && b.second > c.second && b.second > d.second) ||
                 (c.second > a.second && c.second > b.second && d.second > a.second && d.second > b.second)) return false;
        return true;
    }

    return false;
}

void setUnion(int a, int b) {
    int aRoot = setFind(a);
    int bRoot = setFind(b);

    if(aRoot == bRoot)
        return;

    if(height[aRoot] < height[bRoot]) {
        set[aRoot] = bRoot;
        height[bRoot] += height[aRoot];
    }

    else {
        set[bRoot] = aRoot;
        height[aRoot] += height[bRoot];
    }
}

int setFind(int a) {
    if(set[a] == a)
        return a;

    return setFind(set[a]);
}
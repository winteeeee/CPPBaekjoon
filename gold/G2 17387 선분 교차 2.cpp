#include <iostream>
#include <vector>
using namespace std;

class Segment {
private:
    pair<long long, long long> point1;
    pair<long long, long long> point2;

public:
    Segment(int x1, int y1, int x2, int y2);
    pair<long long, long long> getPoint1();
    pair<long long, long long> getPoint2();
};

Segment::Segment(int x1, int y1, int x2, int y2) {
    point1 = {x1, y1};
    point2 = {x2, y2};
}

pair<long long, long long> Segment::getPoint1() {
    return point1;
}

pair<long long, long long> Segment::getPoint2() {
    return point2;
}

long long ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c);
bool isCross(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c, pair<long long, long long> d);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<Segment> segments;
    for(int i = 0; i < 2; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segments.push_back(Segment(x1, y1, x2, y2));
    }

    if(isCross(segments[0].getPoint1(), segments[0].getPoint2(), segments[1].getPoint1(), segments[1].getPoint2())) {
        cout << "1";
    }

    else
        cout << "0";

    return 0;
}

long long ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
    long long val = (a.first * b.second) + (b.first * c.second) + (c.first * a.second) - ((a.first * c.second) + (b.first * a.second) + (c.first * b.second));

    if(val < 0)
        return -1;

    else if(val > 0)
        return 1;

    else
        return 0;
}

bool isCross(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c, pair<long long, long long> d) {
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
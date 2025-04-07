#include <bits/stdc++.h>

using namespace std;

struct point {
	int x{}, y{};
};

int ccw(point &p1, point &p2, point &p3) {
	int res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<point> A(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	cout << ccw(A[0], A[1], A[2]) << "\n";
	return 0;
}

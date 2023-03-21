#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct point {
	point(double _x, double _y) : x(_x), y(_y) { }
	double x{}, y{};
};

int ccw(const point &p1, const point &p2, const point &p3) {
	double res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return abs(res) < EPS ? 0 : res > 0 ? 1 : -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(8);
	for (int i = 0; i < 8; ++i) {
		cin >> A[i];
	}
	vector<int> B(8);
	for (int i = 0; i < 8; ++i) {
		B[i] = i;
	}
	int ans{};
	do {
		bool yes = true;
		for (int i = 0; i < 8; ++i) {
			int x = B[(i + 7) % 8];
			int y = B[(i + 1) % 8];
			int z = B[i];
			if (ccw(point(A[x], 0), point(0, A[y]), point(A[z] / sqrt(2), A[z] / sqrt(2))) > -1) {
				yes = false;
				break;
			}
		}
		if (yes) {
			++ans;
		}
	} while (next_permutation(B.begin(), B.end()));
	cout << ans << "\n";
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct point {
	int x{}, y{};
};

bool operator<(point &p1, point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int ccw(point &p1, point &p2, point &p3) {
	int res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<point> A(N);
		vector<point> B(M);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].x >> A[i].y;
		}
		for (int i = 0; i < M; ++i) {
			cin >> B[i].x >> B[i].y;
		}
		bool yes{};
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				yes = true;
				for (int k = 0; k < N; ++k) {
					if (i == k) {
						continue;
					}
					int res = ccw(A[i], B[j], A[k]);
					if (res == -1 || (res == 0 && ((A[i] < B[j]) ^ (A[k] < A[i])))) {
						yes = false;
						break;
					}
				}
				for (int k = 0; k < M; ++k) {
					if (j == k) {
						continue;
					}
					int res = ccw(A[i], B[j], B[k]);
					if (res == 1 || (res == 0 && ((A[i] < B[j]) ^ (B[j] < B[k])))) {
						yes = false;
						break;
					}
				}
				if (yes) {
					i = N;
					break;
				}
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}

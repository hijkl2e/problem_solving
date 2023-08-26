#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
	ll x{}, y{};
};

bool operator<(point &p1, point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int ccw(point &p1, point &p2, point &p3) {
	ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

bool compare(point &o, point &p1, point &p2) {
	if ((p1 < o) ^ (p2 < o)) {
		return p2 < p1;
	} else {
		return ccw(o, p1, p2) == 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	vector<point> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	vector<point> B(N);
	ll ans{};
	for (int i = 0; i < N; ++i) {
		copy(A.begin(), A.end(), B.begin());
		swap(B[i], B[N - 1]);
		sort(B.begin(), B.end() - 1, [&](point &p1, point &p2) {
			return compare(A[i], p1, p2);
		});
		int p{};
		for (int j = 0; j < N - 1; ++j) {
			p = p == j - 1 ? j : p;
			while ((p + 1) % (N - 1) != j && ccw(A[i], B[j], B[(p + 1) % (N - 1)]) == 1) {
				++p;
			}
			int cnt = (N + p - j - 1) % (N - 1);
			ans += cnt * (cnt - 1);
		}
	}
	ans -= N * (N - 1) * (N - 2) * (N - 3) / 4;
	cout << ans << "\n";
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
	bool operator<(const point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
	bool operator==(const point &p) const {
		return x == p.x && y == p.y;
	}
	bool operator!=(const point &p) const {
		return !(*this == p);
	}
	int x{}, y{};
};

using pi = pair<point, int>;

point solve(point &b1, point &e1, point &b2, point &e2) {
	if (b1.x <= b2.x && e2.x <= e1.x && b2.y <= b1.y && e1.y <= e2.y) {
		return {b2.x, b1.y};
	} else {
		return {-1, -1};
	}
}

vector<vector<pi>> A;
deque<bool> C;

void go(pi &p, bool &dir) {
	int x = p.second;
	p.second = -1;
	int y = lower_bound(A[x].begin(), A[x].end(), p) - A[x].begin() + 2 * dir - 1;
	p = A[x][y];
	if (C[p.second] || y == 0 || y == A[x].size() - 1) {
		dir ^= true;
	}
}

int dist(point &p1, point &p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	vector<point> B(N);
	vector<point> E(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i].x >> B[i].y >> E[i].x >> E[i].y;
	}
	point S = B[0];
	for (int i = 0; i < N; ++i) {
		if (B[i].x > E[i].x || B[i].y > E[i].y) {
			swap(B[i], E[i]);
		}
	}
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		A[i].push_back({B[i], i});
		A[i].push_back({E[i], i});
		for (int j = 0; j < N; ++j) {
			if (i == j) {
				continue;
			}
			point p = solve(B[i], E[i], B[j], E[j]);
			if (p.x != -1) {
				A[i].push_back({p, j});
				A[j].push_back({p, i});
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		sort(A[i].begin(), A[i].end());
	}
	C.resize(N);
	for (int i = 0; i < N; ++i) {
		C[i] = B[i].y == E[i].y;
	}
	vector<point> D;
	pi now{S, 0};
	bool dir = A[0][0].first == S;
	D.push_back(now.first);
	do {
		go(now, dir);
		D.push_back(now.first);
	} while (now.first != S);
	vector<ll> F(D.size());
	for (int i = 1; i < F.size(); ++i) {
		F[i] = dist(D[i - 1], D[i]);
	}
	T %= accumulate(F.begin(), F.end(), 0LL);
	point ans;
	for (int i = 1; i < F.size(); ++i) {
		if (T < F[i]) {
			ans.x = D[i - 1].x + (D[i].x - D[i - 1].x) / F[i] * T;
			ans.y = D[i - 1].y + (D[i].y - D[i - 1].y) / F[i] * T;
			break;
		}
		T -= F[i];
	}
	cout << ans.x << " " << ans.y << "\n";
	return 0;
}

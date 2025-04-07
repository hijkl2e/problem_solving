#include <bits/stdc++.h>

using namespace std;

class UF {
public:
	UF(int N) : par(N), sz(N, 1) {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		return par[x] == x ? x : (par[x] = root(par[x]));
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		par[y] = x;
		sz[x] += sz[y];
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
private:
	vector<int> par, sz;
};

struct point {
	int x{}, y{};
};

bool operator<=(point &p1, point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y <= p2.y);
}

int ccw(point &p1, point &p2, point &p3) {
	int res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

bool solve(vector<point> &A) {
	static vector<int> B(4);
	for (int i = 0; i < 4; ++i) {
		B[i] = ccw(A[i & 2], A[(i & 2) | 1], A[i ^ 2]);
	}
	if (B[0] * B[1] == 1 || B[2] * B[3] == 1) {
		return false;
	}
	int z = count(B.begin(), B.end(), 0);
	if (z == 4) {
		for (int i = 0; i < 4; i += 2) {
			if (A[i + 1] <= A[i]) {
				swap(A[i], A[i + 1]);
			}
		}
		return A[0] <= A[3] && A[2] <= A[1];
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<point> A(2 * N);
	for (int i = 0; i < A.size(); ++i) {
		cin >> A[i].x >> A[i].y;
	}
	UF uf(N);
	vector<point> B;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			B = {A[2 * i], A[2 * i + 1], A[2 * j], A[2 * j + 1]};
			if (solve(B)) {
				uf.unite(i, j);
			}
		}
	}
	int ans_x{}, ans_y{};
	for (int i = 0; i < N; ++i) {
		if (uf.root(i) == i) {
			++ans_x;
			ans_y = max(ans_y, uf.size(i));
		}
	}
	cout << ans_x << "\n" << ans_y << "\n";
	return 0;
}

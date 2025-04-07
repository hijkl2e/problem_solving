#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class FT2D {
public:
	FT2D(int n, int m) : ft(n + 1, vector<T>(m + 1)) { }
	T rsq(int x1, int y1, int x2, int y2) {
		return rsq(x2, y2) - rsq(x1 - 1, y2) - rsq(x2, y1 - 1) + rsq(x1 - 1, y1 - 1);
	}
	T rsq(int x, int y) {
		T res{};
		while (x) {
			int z = y;
			while (z) {
				res += ft[x][z];
				z -= LSOne(z);
			}
			x -= LSOne(x);
		}
		return res;
	}
	void update(int x, int y, T v) {
		while (x < ft.size()) {
			int z = y;
			while (z < ft[x].size()) {
				ft[x][z] += v;
				z += LSOne(z);
			}
			x += LSOne(x);
		}
	}
private:
	T LSOne(T x) {
		return x & -x;
	}
	vector<vector<T>> ft;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> A[i][j];
		}
	}
	FT2D ft(N, N);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			ft.update(i, j, A[i][j]);
		}
	}
	while (M--) {
		int q{}, x1{}, y1{}, x2{}, y2{};
		cin >> q >> x1 >> y1 >> x2;
		if (q == 0) {
			ft.update(x1, y1, x2 - A[x1][y1]);
			A[x1][y1] = x2;
		} else {
			cin >> y2;
			cout << ft.rsq(x1, y1, x2, y2) << "\n";
		}
	}
	return 0;
}

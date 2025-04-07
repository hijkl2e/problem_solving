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
	int N{}, M{}, Q{};
	cin >> N >> M >> Q;
	FT2D ft(N + 1, M + 1);
	while (Q--) {
		int q{}, x1{}, y1{}, x2{}, y2{}, d{};
		cin >> q >> x1 >> y1;
		if (q == 1) {
			cin >> x2 >> y2 >> d;
			ft.update(x1, y1, d);
			ft.update(x2 + 1, y1, -d);
			ft.update(x1, y2 + 1, -d);
			ft.update(x2 + 1, y2 + 1, d);
		} else {
			cout << ft.rsq(x1, y1) << "\n";
		}
	}
	return 0;
}

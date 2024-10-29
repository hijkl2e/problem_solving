#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
	FT(vector<T> &A) : ft(A.size()) {
		for (int i = 1; i < ft.size(); ++i) {
			ft[i] += A[i];
			if (i + LSOne(i) < ft.size()) {
				ft[i + LSOne(i)] += ft[i];
			}
		}
	}
	T rsq(int i, int j) {
		return rsq(j) - rsq(i - 1);
	}
	T rsq(int j) {
		T res{};
		while (j) {
			res += ft[j];
			j -= LSOne(j);
		}
		return res;
	}
	void update(int i, T v) {
		while (i < ft.size()) {
			ft[i] += v;
			i += LSOne(i);
		}
	}
private:
	T LSOne(T x) {
		return x & -x;
	}
	vector<T> ft;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	FT ft(A);
	int M{};
	cin >> M;
	while (M--) {
		int q{}, x{};
		cin >> q >> x;
		if (q == 1) {
			int y{};
			cin >> y;
			ft.update(x, y);
			continue;
		}
		int lo = 0, hi = N;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (ft.rsq(mid) < x) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		cout << hi << "\n";
	}
	return 0;
}

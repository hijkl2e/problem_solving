#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
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
	int TC{};
	cin >> TC;
	while (TC--) {
		int M{}, R{};
		cin >> M >> R;
		vector<int> A(M + 1);
		for (int i = 1; i <= M; ++i) {
			A[i] = R + i;
		}
		FT ft(R + M);
		for (int i = 1; i <= M; ++i) {
			ft.update(R + i, 1);
		}
		for (int i = 0; i < R; ++i) {
			int x{};
			cin >> x;
			cout << ft.rsq(A[x] - 1) << (i == R - 1 ? "\n" : " ");
			ft.update(A[x], -1);
			A[x] = R - i;
			ft.update(A[x], 1);
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
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
		int x{};
		cin >> x;
		A[x] = i;
	}
	FT ft(N);
	for (int i = 1; i <= N; ++i) {
		ft.update(i, 1);
	}
	for (int i = 0; i < N; ++i) {
		int x{};
		ll ans{};
		if (i % 2) {
			x = N - i / 2;
			ans = ft.rsq(A[x] + 1, N);
		} else {
			x = i / 2 + 1;
			ans = ft.rsq(1, A[x] - 1);
		}
		ft.update(A[x], -1);
		cout << ans << "\n";
	}
	return 0;
}

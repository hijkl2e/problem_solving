#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
	T rsq(int i, int j) {
		return (rsq(j) - rsq(i - 1) + MOD) % MOD;
	}
	T rsq(int j) {
		T res{};
		while (j) {
			res = (res + ft[j]) % MOD;
			j -= LSOne(j);
		}
		return res;
	}
	void update(int i, T v) {
		while (i < ft.size()) {
			ft[i] = (ft[i] + v) % MOD;
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
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		++A[i];
	}
	vector<FT<int>> ft(K + 1, FT<int>(N + 1));
	ft[0].update(1, 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			ft[j + 1].update(A[i], ft[j].rsq(A[i] - 1));
		}
	}
	int ans = ft[K].rsq(N + 1);
	cout << ans << "\n";
	return 0;
}

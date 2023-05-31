#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

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
		return res % MOD;
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
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<FT<>> ft(11, FT(N));
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans += ft[10].rsq(A[i] - 1);
		for (int j = 10; j > 1; --j) {
			ft[j].update(A[i], ft[j - 1].rsq(A[i] - 1));
		}
		ft[1].update(A[i], 1);
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}

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
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		C[B[i]] = i;
	}
	FT ft(N + 1);
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ll x = ft.rsq(C[A[i]]);
		ans += x * (N + x - i - C[A[i]] - 1);
		ft.update(C[A[i]] + 1, 1);
	}
	if (ans) {
		cout << "My heart has gone to paradise\n";
		cout << ans << "\n";
	} else {
		cout << "Attention is what I want\n";
	}
	return 0;
}

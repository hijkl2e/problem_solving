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
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	reverse(A.begin(), A.end());
	FT ft1(N);
	FT ft2(N);
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans += ft2.rsq(A[i] - 1);
		ft2.update(A[i], ft1.rsq(A[i] - 1));
		ft1.update(A[i], 1);
	}
	cout << ans << "\n";
	return 0;
}

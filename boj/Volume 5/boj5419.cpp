#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int INF = 1e9 + 7;

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
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<ii> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].second >> A[i].first;
			A[i].second *= -1;
		}
		sort(A.rbegin(), A.rend());
		vector<int> B(N + 1);
		for (int i = 0; i < N; ++i) {
			A[i].second *= -1;
			B[i] = A[i].second;
		}
		B[N] = -INF;
		sort(B.begin(), B.end());
		B.resize(unique(B.begin(), B.end()) - B.begin());
		for (int i = 0; i < N; ++i) {
			A[i].second = lower_bound(B.begin(), B.end(), A[i].second) - B.begin();
		}
		ll ans{};
		FT ft(B.size());
		for (int i = 0; i < N; ++i) {
			ans += ft.rsq(A[i].second);
			ft.update(A[i].second, 1);
		}
		cout << ans << "\n";
	}
	return 0;
}

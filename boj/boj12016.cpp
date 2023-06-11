#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

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
	vector<ii> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end());
	vector<ll> B(N + 1);
	vector<int> C(N + 1, 1);
	FT ft(C);
	ll t{};
	for (int i = 1, j = 2; i <= N; i = j++) {
		int sz = ft.rsq(N);
		t += (A[i].first - A[i - 1].first - 1LL) * sz;
		while (j <= N && A[i].first == A[j].first) {
			++j;
		}
		for (int k = i; k < j; ++k) {
			B[A[k].second] = t + ft.rsq(A[k].second);
		}
		for (int k = i; k < j; ++k) {
			ft.update(A[k].second, -1);
		}
		t += sz;
	}
	for (int i = 1; i <= N; ++i) {
		cout << B[i] << "\n";
	}
	return 0;
}

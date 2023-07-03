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
	vector<int> B(A.begin(), A.end());
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	for (int i = 0; i < N; ++i) {
		A[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin() + 1;
	}
	FT ft(N);
	for (int i = 0; i < N; ++i) {
		cout << i - ft.rsq(A[i]) + 1 << "\n";
		ft.update(A[i], 1);
	}
	return 0;
}

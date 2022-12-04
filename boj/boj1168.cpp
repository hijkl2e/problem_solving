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
	int select(T k) {
		int p = 1;
		while (2 * p < ft.size()) {
			p *= 2;
		}
		int i = 0;
		while (p) {
			if (i + p < ft.size() && k > ft[i + p]) {
				k -= ft[i + p];
				i += p;
			}
			p /= 2;
		}
		return i + 1;
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
	vector<int> A(N + 1, 1);
	FT ft(A);
	int x{};
	cout << "<";
	for (int i = N; i > 0; --i) {
		int res = ft.rsq(x + 1, N);
		if (res >= K) {
			x = ft.select(i - res + K);
		} else {
			x = ft.select((K - res - 1) % i + 1);
		}
		cout << x << (i == 1 ? ">\n" : ", ");
		ft.update(x, -1);
	}
	return 0;
}

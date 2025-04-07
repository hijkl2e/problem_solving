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
private:
	T LSOne(T x) {
		return x & -x;
	}
	vector<T> ft;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N + 1);
	FT ft(N);
	while (M--) {
		int q{}, a{}, b{};
		cin >> q >> a >> b;
		if (q) {
			ft.update(a, b - A[a]);
			A[a] = b;
		} else {
			if (a > b) {
				swap(a, b);
			}
			cout << ft.rsq(a, b) << "\n";
		}
	}
	return 0;
}

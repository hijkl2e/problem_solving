#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class FT {
public:
	FT() { }
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

vector<int> A;
vector<FT<ll>> ft(2);

ll solve(int x) {
	return x ? ft[x % 2].rsq(x) + (x % 2 ? A[0] + A[1] : 0) - 2 * (A[x] - A[0]) : 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.resize(N + 1);
	for (int i = 0; i <= N; ++i) {
		cin >> A[i];
	}
	vector<ll> B(N + 1);
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= N; ++j) {
			B[j] = ((i + j) % 2 ? 8 : 4) * A[j];
		}
		ft[i] = FT(B);
	}
	int M{};
	cin >> M;
	while (M--) {
		int q{}, a{}, b{};
		cin >> q >> a >> b;
		if (q == 1) {
			if (a) {
				for (int i = 0; i < 2; ++i) {
					ft[i].update(a, ((i + a) % 2 ? 8 : 4) * (b - A[a]));
				}
			}
			A[a] = b;
		} else {
			ll ans = solve(b) - solve(a);
			cout << ans << "\n";
		}
	}
	return 0;
}

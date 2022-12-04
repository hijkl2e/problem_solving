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
	int N{}, Q{};
	cin >> N >> Q;
	vector<ll> V(6);
	for (int i = 0; i < 6; ++i) {
		cin >> V[i];
	}
	string S;
	cin >> S;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		A[i] = S[i - 1] - '1';
	}
	vector<FT<>> ft(6, FT(N));
	for (int i = 1; i <= N; ++i) {
		ft[A[i]].update(i, 1);
	}
	while (Q--) {
		int q{}, a{}, b{};
		cin >> q >> a >> b;
		if (q == 1) {
			ft[A[a]].update(a, -1);
			A[a] = b - 1;
			ft[A[a]].update(a, 1);
		} else if (q == 2) {
			V[a - 1] = b;
		} else {
			ll val{};
			for (int i = 0; i < 6; ++i) {
				val += V[i] * ft[i].rsq(a, b);
			}
			cout << val << "\n";
		}		
	}
	return 0;
}

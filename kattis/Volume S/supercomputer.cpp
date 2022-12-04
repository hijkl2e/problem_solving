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
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N + 1);
	FT ft(N);
	while (K--) {
		char c{};
		cin >> c;
		if (c == 'F') {
			int i{};
			cin >> i;
			A[i] ^= 1;
			ft.update(i, 2 * A[i] - 1);
		} else {
			int l{}, r{};
			cin >> l >> r;
			cout << ft.rsq(l, r) << "\n";
		}		
	}
	return 0;
}

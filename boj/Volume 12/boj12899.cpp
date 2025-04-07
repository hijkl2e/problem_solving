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
	int N{};
	cin >> N;
	FT ft(2000001);
	while (N--) {
		int q{}, x{};
		cin >> q >> x;
		if (q == 1) {
			ft.update(x, 1);
		} else {
			int y = ft.select(x);
			cout << y << "\n";
			ft.update(y, -1);
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
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
	FT ft(1e6);
	int N{};
	cin >> N;
	while (N--) {
		int a{}, b{}, c{};
		cin >> a >> b;
		if (a == 1) {
			int ans = ft.select(b);
			ft.update(ans, -1);
			cout << ans << "\n";
		} else {
			cin >> c;
			ft.update(b, c);
		}
	}
	return 0;
}

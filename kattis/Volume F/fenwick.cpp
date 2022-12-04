#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
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
	FT ft(N);
	while (Q--) {
		char c{};
		cin >> c;
		if (c == '+') {
			int i{}, d{};
			cin >> i >> d;
			ft.update(i + 1, d);
		} else {
			int i{};
			cin >> i;
			cout << ft.rsq(i) << "\n";
		}
	}
	return 0;
}

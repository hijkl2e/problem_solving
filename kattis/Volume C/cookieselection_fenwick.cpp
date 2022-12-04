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
	string tok;
	vector<int> A;
	for (int i = 0; cin >> tok; ++i) {
		int d{};
		if (tok != "#") {
			d = stoi(tok);
		}
		A.push_back(d);
	}
	vector<int> B(A.begin(), A.end());
	sort(B.begin(), B.end());
	auto it = unique(B.begin(), B.end());
	B.erase(it, B.end());
	for (int i = 0; i < A.size(); ++i) {
		A[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
	}
	FT ft(B.size());
	int cnt{};
	for (int d : A) {
		if (d) {
			ft.update(d, 1);
			++cnt;
		} else {
			d = ft.select(cnt / 2 + 1);
			cout << B[d] << "\n";
			ft.update(d, -1);
			--cnt;
		}
	}
	return 0;
}

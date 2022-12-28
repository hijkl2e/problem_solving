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
	map<int, int> n2i;
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		n2i[x] = i;
	}
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		A[n2i[x]] = i + 1;
	}
	FT ft(N);
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		yes ^= ft.rsq(A[i] + 1, N) & 1;
		ft.update(A[i], 1);
	}
	cout << (yes ? "Possible" : "Impossible") << "\n";
	return 0;
}

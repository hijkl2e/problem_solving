#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using query = tuple<int, int, int, int>;

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
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		A[i] = {x, i + 1};
	}
	sort(A.rbegin(), A.rend());
	int M{};
	cin >> M;
	vector<query> B(M);
	for (int i = 0; i < M; ++i) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		B[i] = {c, a, b, i};
	}
	sort(B.rbegin(), B.rend());
	FT ft(N);
	vector<int> ans(M);
	for (int i = 0, j = 0; i < M; ++i) {
		auto &[a, b, c, d] = B[i];
		while (j < A.size()) {
			auto &[e, f] = A[j];
			if (a < e) {
				ft.update(f, 1);
				++j;
			} else {
				break;
			}
		}
		ans[d] = ft.rsq(b, c);
	}
	for (int x : ans) {
		cout << x << "\n";
	}
	return 0;
}

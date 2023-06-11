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
	vector<vector<int>> A(4, vector<int>(N));
	for (int i = 1; i < 4; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<int> B(3000003);
	for (int i = 1; i < 4; ++i) {
		int x = i == 1 ? 1 : i == 2 ? 2 : 5;
		for (int j = 0; j < N; ++j) {
			A[i][j] += A[i - 1][j];
			B[A[i - 1][j] + 1] += x;
			B[A[i][j] + 1] -= x;
		}
	}
	partial_sum(B.begin(), B.end(), B.begin());
	vector<int> C(1300001, 1);
	FT ft(C);
	int M{};
	cin >> M;
	while (M--) {
		int x{};
		cin >> x;
		int y = ft.select(x);
		cout << B[y] << "\n";
		ft.update(y, -1);
	}
	return 0;
}

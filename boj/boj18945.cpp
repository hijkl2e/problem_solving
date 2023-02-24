#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

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
private:
	T LSOne(T x) {
		return x & -x;
	}
	vector<T> ft;
};

ii find(vector<string> &A, char c) {
	ii ret{-1, -1};
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A[i].size(); ++j) {
			if (A[i][j] == c) {
				if (ret.first == -1) {
					ret = {i, j};
				} else {
					return {-1, -1};
				}
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		int R{}, C{};
		cin >> R >> C;
		cin.ignore();
		vector<string> D(R);
		for (int j = R - 1; j >= 0; --j) {
			getline(cin, D[j]);
		}
		auto [x, y] = find(D, 'B');
		bool flag = x == -1;
		if (flag) {
			for (int j = 0; j < R; ++j) {
				for (int k = 0; k < C; ++k) {
					D[j][k] = D[j][k] == 'A' ? 'B' : D[j][k] == 'B' ? 'A' : 'C';
				}
			}
			tie(x, y) = find(D, 'B');
		}
		A[i] = flag ? -1 : 1;
		int r = R, c = C, p{}, q{};
		for (int j = 0; j < R; ++j) {
			for (int k = 0; k < C; ++k) {
				if (D[j][k] != 'A') {
					continue;
				}
				if (j <= x && k <= y) {
					++p;
				} else {
					if (j < x) {
						c = min(c, k);
					} else if (k < y) {
						r = min(r, j);
					}
					++q;
				}
			}
		}
		flag = false;
		for (int j = x; j < r; ++j) {
			for (int k = y; k < c; ++k) {
				if (D[j][k] == 'A') {
					flag = true;
				}
			}
		}
		A[i] *= q * (1LL << 40) - (1LL << (40 - p - flag));
	}
	FT ft(A);
	int T{};
	cin >> T;
	while (T--) {
		int K{}, U{}, V{};
		cin >> K >> U >> V;
		ft.update(K, -2 * A[K]);
		A[K] *= -1;
		cout << (ft.rsq(U, V) > 0 ? "Ahgus" : "Bagus") << "\n";
	}
	return 0;
}

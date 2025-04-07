#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using iii = pair<ii, int>;
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
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<ii> A(N);
		for (auto &[x, y] : A) {
			cin >> x >> y;
			++x, ++y;
		}
		sort(A.begin(), A.end());
		vector<query> B(M);
		vector<iii> C;
		for (auto &[l, r, b, t] : B) {
			cin >> l >> r >> b >> t;
			++l, ++r, ++b, ++t;
			C.push_back({{l - 1, b - 1}, 1});
			C.push_back({{l - 1, t}, -1});
			C.push_back({{r, b - 1}, -1});
			C.push_back({{r, t}, 1});
		}
		sort(C.begin(), C.end());
		FT ft(100001);
		int ans{};
		for (int i = 0, j = 0; i < N || j < C.size();) {
			if (j == C.size() || (i < N && A[i] <= C[j].first)) {
				ft.update(A[i++].second, 1);
			} else {
				ans += C[j].second * ft.rsq(C[j].first.second);
				++j;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

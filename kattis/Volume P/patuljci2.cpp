#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

template <typename T = ll>
class Seg {
public:
	Seg(vector<T> &A) : n(A.size()), st(2 * A.size()) {
		for (int i = 0; i < n; ++i) {
			st[i + n] = {A[i], 1};
		}
		for (int i = n - 1; i > 0; --i) {
			st[i] = conquer(st[2 * i], st[2 * i + 1]);
		}
	}
	ii rmq(int l, int r) {
		ii ret;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = conquer(ret, st[l++]);
			}
			if (r & 1) {
				ret = conquer(st[--r], ret);
			}
		}
		return ret;
	}
private:
	ii conquer(ii &a, ii &b) {
		if (a.first == b.first) {
			return {a.first, a.second + b.second};
		} else if (a.second > b.second) {
			return {a.first, a.second - b.second};
		} else {
			return {b.first, b.second - a.second};
		}
	}
	int n;
	vector<ii> st;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, C{};
	cin >> N >> C;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> B(C + 1);
	for (int i = 1; i <= N; ++i) {
		B[A[i]].push_back(i);
	}
	Seg seg(A);
	int M{};
	cin >> M;
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		auto [x, y] = seg.rmq(a, b + 1);
		int cnt = upper_bound(B[x].begin(), B[x].end(), b)
				- lower_bound(B[x].begin(), B[x].end(), a);
		if (cnt > (b - a + 1) / 2) {
			cout << "yes " << x << "\n";
		} else {
			cout << "no\n";
		}
	}
	return 0;
}

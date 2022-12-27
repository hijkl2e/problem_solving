#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	void update(int p, T val) {
		for (st[p += n] = val; p > 1; p /= 2) {
			st[p / 2] = max(st[p], st[p ^ 1]);
		}
	}
	T rmq(int l, int r) {
		T ret{};
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = max(ret, st[l++]);
			}
			if (r & 1) {
				ret = max(st[--r], ret);
			}
		}
		return ret;
	}
private:
	int n;
	vector<T> st;
};

struct event {
	int x{}, l{}, y{}, t{}, z{};
	bool operator<(event &e) {
		return x < e.x || (x == e.x && z < e.z);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<event> A(2 * N);
	for (int i = 0; i < 2 * N; i += 2) {
		int xl{}, xr{}, y{};
		char c{};
		cin >> xl >> xr >> y >> c;
		A[i] = {xl, xr - xl + 1, y, c == 'S', 1};
		A[i + 1] = {xr + 1, xr - xl + 1, y, c == 'S', -1};
	}
	vector<int> Y(N + 2);
	for (int i = 0; i < N; ++i) {
		Y[i] = A[2 * i].y;
	}
	Y.back() = 2e9;
	sort(Y.begin(), Y.end());
	Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
	for (int i = 0; i < 2 * N; i += 2) {
		A[i].y = A[i + 1].y = lower_bound(Y.begin(), Y.end(), A[i].y) - Y.begin();
	}
	sort(A.begin(), A.end());
	vector<set<int>> S(2);
	for (int i = 0; i < 2; ++i) {
		S[i].insert(0);
		S[i].insert(Y.size() - 1);
	}
	Seg<int> seg(Y.size());
	ll ans{}, sum{};
	for (int i = 0; i < 2 * N;) {
		int X = A[i].x;
		while (i < 2 * N && A[i].x == X) {
			auto &e = A[i++];
			if (e.z == -1) {
				S[e.t].erase(e.y);
				seg.update(e.y, 0);
			}
			auto it = S[e.t].upper_bound(e.y);
			int r1 = *it, l1 = *--it;
			it = S[e.t ^ 1].upper_bound(e.y);
			int r2 = *it, l2 = *--it;
			if (l1 < l2 && r2 < r1) {
				sum += e.z * (min(seg.rmq(l1 + 1, l2 + 1), seg.rmq(r2, r1)) + e.l);
			} else {
				sum += e.z * max(e.l - seg.rmq(l1 < l2 ? e.y : (l2 + 1), r2 < r1 ? e.y + 1 : r2), 0);
			}
			if (e.z == 1) {
				S[e.t].insert(e.y);
				seg.update(e.y, e.l);
			}
		}
		ans = max(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}

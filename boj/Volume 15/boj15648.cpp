#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9 + 7;

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
		T ret = -INF;
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, k{}, d{};
	cin >> N >> k >> d;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(k);
	Seg<int> seg(500001);
	for (int x : A) {
		int y = max(B[x % k], seg.rmq(max(x - d, 0), min(x + d + 1, 500001))) + 1;
		B[x % k] = y;
		seg.update(x, y);
	}
	int ans = *max_element(B.begin(), B.end());
	cout << ans << "\n";
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class Seg {
public:
	Seg(vector<T> &v) : n(v.size()), st(2 * v.size()), A(v) {
		for (int i = 0; i < n; ++i) {
			st[i + n] = i;
		}
		for (int i = n - 1; i > 0; --i) {
			st[i] = conquer(st[2 * i], st[2 * i + 1]);
		}
	}
	int rmq(int l, int r) {
		int ret = l;
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
	int conquer(int a, int b) {
		return A[a] < A[b] ? a : b;
	}
	int n{};
	vector<T> st, &A;
};

vector<ll> H;

ll solve(Seg<> &seg, int l, int r) {
	if (l == r) {
		return 0;
	}
	int idx = seg.rmq(l, r);
	ll ret = (r - l) * H[idx];
	ret = max(ret, solve(seg, l, idx));
	ret = max(ret, solve(seg, idx + 1, r));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	H.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}
	Seg seg(H);
	cout << solve(seg, 0, N) << "\n";
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<T> &A) : n(A.size()), st(2 * A.size()) {
		copy(A.begin(), A.end(), st.begin() + n);
		for (int i = n - 1; i > 0; --i) {
			st[i] = max(st[2 * i], st[2 * i + 1]);
		}
	}
	void update(int p, T val) {
		for (st[p += n] = val; p > 1; p /= 2) {
			st[p / 2] = max(st[p], st[p ^ 1]);
		}
	}
	int query(int l, int r, T val) {
		int L = -1, R = -1;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if ((l & 1) && st[l++] > val) {
				L = max(L, l - 1);
			}
			if ((r & 1) && st[--r] > val) {
				R = r;
			}
		}
		int p = L == -1 ? R == -1 ? n : R : L;
		while (p < n) {
			p = 2 * p + (st[2 * p] <= val);
		}
		return p - n;
	}
private:
	int n;
	vector<T> st;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> D(N);
	for (int i = 0; i < N; ++i) {
		cin >> D[i];
	}
	Seg seg(D);
	int R = K;
	int ans{};
	for (int i = 0; i < N; ++i) {
		if (D[i] == 0) {
			continue;
		}
		int last = D[i];
		while (true) {
			R = min(R + 1, N);
			int idx = seg.query(i + 1, R, last);
			if (idx == 0) {
				break;
			}
			last = D[idx];
			D[idx] = 0;
			seg.update(idx, 0);
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}

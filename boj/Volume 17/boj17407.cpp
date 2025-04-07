#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<int> &A) : n(A.size()), st(2 * A.size()) {
		for (int i = 0; i < n; ++i) {
			st[n + i] = {A[i], A[i]};
		}
		for (int i = n - 1; i > 0; --i) {
			st[i] = conquer(st[2 * i], st[2 * i + 1]);
		}
	}
	void update(int p, int val) {
		st[p += n] = {val, val};
		for (p /= 2; p > 0; p /= 2) {
			st[p] = conquer(st[2 * p], st[2 * p + 1]);
		}
	}
	int query() {
		return st[1].first;
	}
private:
	ii conquer(ii &L, ii &R) {
		auto &[l1, s1] = L;
		auto &[l2, s2] = R;
		return {min(l1, s1 + l2), s1 + s2};
	}
	int n;
	vector<ii> st;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A(1 << 17);
	for (int i = 0; i < S.size(); ++i) {
		A[i] = S[i] == '(' ? 1 : -1;
	}
	int cnt = accumulate(A.begin(), A.end(), 0);
	Seg seg(A);
	int M{};
	cin >> M;
	int ans{};
	while (M--) {
		int x{};
		cin >> x;
		int y = A[--x] == 1 ? -1 : 1;
		seg.update(x, y);
		cnt += 2 * y;
		A[x] *= -1;
		if (seg.query() >= 0 && cnt == 0) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9 + 7;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<T> &A) : n(A.size()), st(2 * A.size()) {
		copy(A.begin(), A.end(), st.begin() + n);
		for (int i = n - 1; i > 0; --i) {
			st[i] = min(st[2 * i], st[2 * i + 1]);
		}
	}
	void update(int p, T val) {
		for (st[p += n] = val; p > 1; p /= 2) {
			st[p / 2] = min(st[p], st[p ^ 1]);
		}
	}
	T rmq(int l, int r) {
		T ret = INF;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = min(ret, st[l++]);
			}
			if (r & 1) {
				ret = min(st[--r], ret);
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
	string S;
	getline(cin, S);
	int cnt{};
	vector<int> A(S.size());
	for (int i = 0; i < A.size(); ++i) {
		A[i] = S[i] == '(' ? ++cnt : cnt--;
	}
	Seg seg(A);
	int M{};
	cin >> M;
	int ans{};
	while (M--) {
		int l{}, r{};
		cin >> l >> r;
		--l, --r;
		if ((r - l) % 2 && S[l] == '(' && A[l] == A[r] && seg.rmq(l, r + 1) == A[l]) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}

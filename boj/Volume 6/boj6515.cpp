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
			st[i] = max(st[2 * i], st[2 * i + 1]);
		}
	}
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
	int N{}, Q{};
	while (cin >> N >> Q) {
		vector<int> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
			A[i] += 100000;
		}
		vector<int> B(200001);
		for (int i = 1; i <= N; ++i) {
			++B[A[i]];
		}
		vector<int> L(N + 1);
		vector<int> R(N + 1);
		for (int i = 1; i <= N; ++i) {
			L[i] = (i > 1 && A[i] == A[i - 1] ? L[i - 1] : 0) + 1;
		}
		for (int i = N; i > 0; --i) {
			R[i] = (i < N && A[i] == A[i + 1] ? R[i + 1] : 0) + 1;
		}
		Seg seg(B);
		while (Q--) {
			int a{}, b{};
			cin >> a >> b;
			int ans = A[a] == A[b] ? (b - a + 1) : max({seg.rmq(A[a] + 1, A[b]), R[a], L[b]});
			cout << ans << "\n";
		}
	}
	return 0;
}

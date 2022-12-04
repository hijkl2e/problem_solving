#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class MergeT {
public:
	MergeT(vector<T> &A) : n(A.size()), st(2 * A.size()) {
		for (int i = 0; i < n; ++i) {
			st[i + n].push_back(A[i]);
		}
		for (int i = n - 1; i > 0; --i) {
			int l = 2 * i;
			int r = 2 * i + 1;
			merge(st[l].begin(), st[l].end(), st[r].begin(), st[r].end(),
					back_inserter(st[i]));
		}
	}
	int query(int l, int r, T val) {
		int ret{};
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret += query(l++, val);
			}
			if (r & 1) {
				ret += query(--r, val);
			}
		}
		return ret;
	}
private:
	int query(int p, T val) {
		return st[p].end() - upper_bound(st[p].begin(), st[p].end(), val);
	}
	int n;
	vector<vector<T>> st;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(A.begin(), A.end());
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	for (int i = 0; i < N; ++i) {
		A[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
	}
	vector<int> C(B.size(), 1e9);
	for (int i = N - 1; i >= 0; --i) {
		int x = A[i];
		A[i] = C[A[i]];
		C[x] = i;
	}
	MergeT mergeT(A);
	int Q{}, q{};
	cin >> Q;
	while (Q--) {
		int x{}, r{};
		cin >> x >> r;
		int l = x + q;
		q = mergeT.query(l - 1, r, r - 1);
		cout << q << "\n";
	}
	return 0;
}

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

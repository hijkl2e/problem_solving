#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int N, K;
ii ans{-1, -1};
vector<int> A;

void heapify(int k, int n) {
	int l = 2 * k, r = 2 * k + 1;
	int p = r <= n ? A[l] < A[r] ? l : r : (l <= n ? l : 0);
	if (p && A[p] < A[k]) {
		swap(A[k], A[p]);
		if (--K == 0) {
			ans = {A[k], A[p]};
		}
		heapify(p, n);
	}
}

void build_min_heap() {
	for (int i = N / 2; i > 0; --i) {
		heapify(i, N);
	}
}

void heap_sort() {
	build_min_heap();
	for (int i = N; i > 1; --i) {
		swap(A[i], A[1]);
		if (--K == 0) {
			ans = {A[i], A[1]};
		}
		heapify(1, i - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	A.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	heap_sort();
	if (ans.first == -1) {
		cout << "-1\n";
	} else {
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}

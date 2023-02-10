#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int K;
ii ans{-1, -1};
vector<int> A;

int partition(int p, int r) {
	int x = A[r];
	int i = p;
	for (int j = p; j < r; ++j) {
		if (A[j] <= x) {
			swap(A[i], A[j]);
			if (--K == 0) {
				ans = {A[i], A[j]};
			}
			++i;
		}
	}
	if (i < r) {
		swap(A[i], A[r]);
		if (--K == 0) {
			ans = {A[i], A[r]};
		}
	}
	return i;
}

int select(int p, int r, int q) {
	if (p == r) {
		return A[p];
	}
	int t = partition(p, r);
	int k = t - p + 1;
	if (q < k) {
		return select(p, t - 1, q);
	} else if (q > k) {
		return select(t + 1, r, q - k);
	} else {
		return A[t];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q >> K;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	select(0, N - 1, Q);
	if (ans.first == -1) {
		cout << "-1\n";
	} else {
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}

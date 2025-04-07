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

void quick_sort(int p, int r) {
	if (p < r) {
		int q = partition(p, r);
		quick_sort(p, q - 1);
		quick_sort(q + 1, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N >> K;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	quick_sort(0, N - 1);
	if (ans.first == -1) {
		cout << "-1\n";
	} else {
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}

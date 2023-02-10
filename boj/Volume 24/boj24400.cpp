#include <bits/stdc++.h>

using namespace std;

int cnt;
bool yes;
vector<int> A, B;

bool solve(int x) {
	return A[x] == B[x];
}

int partition(int p, int r) {
	int x = A[r];
	int i = p;
	for (int j = p; j < r; ++j) {
		if (A[j] <= x) {
			cnt += solve(i) + solve(j);
			swap(A[i], A[j]);
			cnt -= solve(i) + solve(j);
			yes |= cnt == 0;
			++i;
		}
	}
	if (i < r) {
		cnt += solve(i) + solve(r);
		swap(A[i], A[r]);
		cnt -= solve(i) + solve(r);
		yes |= cnt == 0;
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
	cin >> N >> Q;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	for (int i = 0; i < N; ++i) {
		if (A[i] != B[i]) {
			++cnt;
		}
	}
	yes = cnt == 0;
	select(0, N - 1, Q);
	cout << yes << "\n";
	return 0;
}

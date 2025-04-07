#include <bits/stdc++.h>

using namespace std;

int cnt;
bool yes;
vector<int> A, B, C;

bool solve(int x) {
	return A[x] == B[x];
}

void merge(int p, int q, int r) {
	int i = p, j = q + 1, k = p;
	while (i <= q && j <= r) {
		if (A[i] <= A[j]) {
			C[k++] = A[i++];
		} else {
			C[k++] = A[j++];
		}
	}
	while (i <= q) {
		C[k++] = A[i++];
	}
	while (j <= r) {
		C[k++] = A[j++];
	}
	i = p;
	while (i <= r) {
		cnt += solve(i);
		A[i] = C[i];
		cnt -= solve(i);
		yes |= cnt == 0;
		++i;
	}
}

void merge_sort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
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
	C.resize(N);
	merge_sort(0, N - 1);
	cout << yes << "\n";
	return 0;
}

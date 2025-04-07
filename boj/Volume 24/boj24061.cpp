#include <bits/stdc++.h>

using namespace std;

int K;
vector<int> A, B;

void merge(int p, int q, int r) {
	int i = p, j = q + 1, k = p;
	while (i <= q && j <= r) {
		if (A[i] <= A[j]) {
			B[k++] = A[i++];
		} else {
			B[k++] = A[j++];
		}
	}
	while (i <= q) {
		B[k++] = A[i++];
	}
	while (j <= r) {
		B[k++] = A[j++];
	}
	i = p;
	while (i <= r) {
		if (K-- > 0) {
			A[i] = B[i];
		}
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
	cin >> N >> K;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	B.resize(N);
	merge_sort(0, N - 1);
	if (K > 0) {
		cout << "-1\n";
	} else {
		for (int i = 0; i < N; ++i) {
			cout << A[i] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}

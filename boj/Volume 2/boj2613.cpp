#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int lo = *max_element(A.begin(), A.end()) - 1, hi = 3e4;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int cnt{};
		for (int i = 0, j = 1; i < N; i = j++) {
			int sum = A[i];
			while (j < N && sum + A[j] <= mid) {
				sum += A[j++];
			}
			++cnt;
		}
		if (cnt > M) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	vector<int> B;
	for (int i = 0, j = 1; i < N; i = j++) {
		int sum = A[i];
		while (j < N && sum + A[j] <= hi) {
			sum += A[j++];
		}
		B.push_back(j - i);
	}
	while (B.size() < M) {
		int p{};
		while (B[p] == 1) {
			++p;
		}
		B.insert(B.begin() + p + 1, 1);
		--B[p];
	}
	cout << hi << "\n";
	for (int i = 0; i < M; ++i) {
		cout << B[i] << (i == M - 1 ? "\n" : " ");
	}
	return 0;
}

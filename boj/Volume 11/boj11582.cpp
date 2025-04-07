#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int K{};
	cin >> K;
	K = N / K;
	for (int i = 0; i < N; i += K) {
		sort(A.begin() + i, A.begin() + i + K);
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}

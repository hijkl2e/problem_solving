#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{-1, 4, 11, 23, 40, 60, 77, 89, 96, 100};
	int N{}, K{};
	cin >> N >> K;
	vector<int> B(K);
	for (int i = 0; i < K; ++i) {
		cin >> B[i];
	}
	vector<int> C(K);
	for (int i = 0; i < K; ++i) {
		int x = 100 * B[i] / N;
		C[i] = lower_bound(A.begin(), A.end(), x) - A.begin();
	}
	for (int i = 0; i < K; ++i) {
		cout << C[i] << (i == K - 1 ? "\n" : " ");
	}
	return 0;
}

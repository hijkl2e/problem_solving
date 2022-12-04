#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A{0};
	for (int i = 0; i < M; ++i) {
		if (i % 3 == 1) {
			A.push_back(2);
			continue;
		}
		for (auto &x : A) {
			x ^= 2;
		}
		if (i % 3 == 0) {
			A.push_back(0);
		}
	}
	A.resize(N, 4);
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}

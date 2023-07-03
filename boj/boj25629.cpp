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
	int x{}, y{};
	for (int i = 0; i < N; ++i) {
		if (A[i] % 2) {
			++x;
		} else {
			++y;
		}
	}
	cout << (x == (N + 1) / 2 && y == N / 2) << "\n";
	return 0;
}

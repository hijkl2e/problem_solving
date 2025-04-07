#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A;
	if (N % 2) {
		A.push_back(1);
	}
	for (int i = 0; i < N / 2; ++i) {
		A.push_back(2 * (i + 1) - i % 2 + N % 2);
		A.push_back(2 * i + 1 + i % 2 + N % 2);
	}
	cout << "YES\n";
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}

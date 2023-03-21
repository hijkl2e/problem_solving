#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	nth_element(A.begin(), A.begin() + K - 1, A.end());
	cout << A[K - 1] << "\n";
	return 0;
}

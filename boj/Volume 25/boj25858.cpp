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
	int sum = accumulate(A.begin(), A.end(), 0);
	K /= sum;
	for (int i = 0; i < N; ++i) {
		cout << K * A[i] << "\n";
	}
	return 0;
}

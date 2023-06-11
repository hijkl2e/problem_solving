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
	int t = accumulate(A.begin(), A.end(), 0) + 8 * (N - 1);
	cout << t / 24 << " " << t % 24 << "\n";
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{}, N{};
	cin >> T >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int sum = accumulate(A.begin(), A.end(), 0);
	cout << "Padaeng_i " << (sum >= T ? "Happy" : "Cry") << "\n";
	return 0;
}

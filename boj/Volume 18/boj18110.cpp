#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	if (N == 0) {
		cout << "0\n";
		return 0;
	}
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int x = 3 * N / 20 + (3 * N % 20 >= 10);
	A.erase(A.begin(), A.begin() + x);
	A.erase(A.end() - x, A.end());
	int sum = accumulate(A.begin(), A.end(), 0);
	int ans = sum / A.size() + (sum % A.size() >= (A.size() + 1) / 2);
	cout << ans << "\n";
	return 0;
}

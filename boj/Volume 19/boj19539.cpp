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
	int sum1 = accumulate(A.begin(), A.end(), 0);
	int sum2{};
	for (int i = 0; i < N; ++i) {
		sum2 += A[i] / 2;
	}
	cout << (sum1 % 3 == 0 && sum2 >= sum1 / 3 ? "YES" : "NO") << "\n";
	return 0;
}

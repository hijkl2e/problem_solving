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
	for (int i = 1; i < N; ++i) {
		int g = gcd(A[0], A[i]);
		cout << A[0] / g << "/" << A[i] / g << "\n";
	}
	return 0;
}

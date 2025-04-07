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
	sort(A.rbegin(), A.rend());
	int x{}, y{};
	for (int i = 0; i < N; ++i) {
		if (i % 2 == 0) {
			x += A[i];
		} else {
			y += A[i];
		}
	}
	cout << x << " " << y << "\n";
	return 0;
}

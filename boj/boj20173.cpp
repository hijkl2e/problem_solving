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
	bool yes = *max_element(A.begin(), A.end()) < 3;
	int x{};
	for (int i = 0; i < N; ++i) {
		x = abs(A[i] - x);
		yes &= x < 2;
	}
	yes &= x == 0;
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}

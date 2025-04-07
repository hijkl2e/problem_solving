#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, x{};
	cin >> N >> x;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(x + 1);
	for (int i = 0; i < N; ++i) {
		++B[A[i]];
	}
	bool yes = true;
	for (int i = 1; i < x; ++i) {
		if (B[i] % (i + 1)) {
			yes = false;
			break;
		}
		B[i + 1] += B[i] / (i + 1);
	}
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}

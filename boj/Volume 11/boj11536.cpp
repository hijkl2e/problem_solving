#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<string> B(A.begin(), A.end());
	sort(B.begin(), B.end());
	if (A == B) {
		cout << "INCREASING\n";
	} else {
		reverse(B.begin(), B.end());
		cout << (A == B ? "DECREASING" : "NEITHER") << "\n";
	}
	return 0;
}

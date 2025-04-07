#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	vector<int> A((1 << K) - 1);
	for (int i = 0; i < A.size(); ++i) {
		cin >> A[i];
	}
	for (int i = K - 1; i >= 0; --i) {
		for (int j = (1 << i) - 1; j < A.size(); j += (1 << (i + 1))) {
			cout << (j == (1 << i) - 1 ? "" : " ") << A[j];
		}
		cout << "\n";
	}
	return 0;
}

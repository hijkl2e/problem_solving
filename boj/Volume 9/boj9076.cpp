#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		vector<int> A(5);
		for (int i = 0; i < 5; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		if (A[3] - A[1] < 4) {
			cout << A[1] + A[2] + A[3] << "\n";
		} else {
			cout << "KIN\n";
		}
	}
	return 0;
}

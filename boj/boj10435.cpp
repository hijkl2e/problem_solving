#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int K{}, N{};
		cin >> K >> N;
		vector<int> A;
		while (N--) {
			int idx = find(A.begin(), A.end(), 0) - A.begin();
			if (idx == A.size()) {
				A.resize(A.size() + 1);
			}
			for (int i = 0; i < idx; ++i) {
				--A[i];
			}
			A[idx] = idx + 1;
		}
		cout << K << " " << A.size();
		for (int i = 0; i < A.size(); ++i) {
			cout << (i % 10 ? " " : "\n") << A[i];
		}
		cout << "\n";
	}
	return 0;
}

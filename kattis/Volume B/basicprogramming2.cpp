#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, t{};
	cin >> N >> t;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	if (t == 1) {
		bool yes = false;
		for (int i = 0; i < N; ++i) {
			if (binary_search(A.begin() + i + 1, A.end(), 7777 - A[i])) {
				yes = true;
				break;
			}
		}
		cout << (yes ? "Yes" : "No") << "\n";
	} else if (t == 2) {
		if (unique(A.begin(), A.end()) == A.end()) {
			cout << "Unique\n";
		} else {
			cout << "Contains duplicate\n";
		}
	} else if (t == 3) {
		int ans = -1;
		for (int i = 0; i + N / 2 < N; ++i) {
			if (A[i] == A[i + N / 2]) {
				ans = A[i];
				break;
			}
		}
		cout << ans << "\n";
	} else if (t == 4) {
		if (N % 2) {
			cout << A[N / 2] << "\n";
		} else {
			cout << A[N / 2 - 1] << " " << A[N / 2] << "\n";
		}
	} else {
		auto beg = lower_bound(A.begin(), A.end(), 100);
		auto end = lower_bound(A.begin(), A.end(), 1000);
		for (auto it = beg; it != end; ++it) {
			if (it != beg) {
				cout << " ";
			}
			cout << *it;
		}
		cout << "\n";
	}
	return 0;
}

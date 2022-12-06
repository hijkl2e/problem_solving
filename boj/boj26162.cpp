#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> P(119, true);
	P[0] = P[1] = false;
	for (int i = 2; i < P.size(); ++i) {
		if (P[i]) {
			for (int j = 2 * i; j < P.size(); j += i) {
				P[j] = false;
			}
		}
	}
	deque<bool> A(119);
	for (int i = 2; i < P.size(); ++i) {
		for (int j = i; P[i] && i + j < A.size(); ++j) {
			if (P[j]) {
				A[i + j] = true;
			}
		}
	}
	int N{};
	cin >> N;
	while (N--) {
		int x{};
		cin >> x;
		cout << (A[x] ? "Yes" : "No") << "\n";
	}
	return 0;
}

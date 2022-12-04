#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, t{};
	cin >> N >> t;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	if (t == 1) {
		cout << "7\n";
	} else if (t == 2) {
		if (A[0] > A[1]) {
			cout << "Bigger\n";
		} else if (A[0] == A[1]) {
			cout << "Equal\n";
		} else {
			cout << "Smaller\n";
		}
	} else if (t == 3) {
		sort(A.begin(), A.begin() + 3);
		cout << A[1] << "\n";
	} else if (t == 4) {
		cout << accumulate(A.begin(), A.end(), 0LL) << "\n";
	} else if (t == 5) {
		ll sum{};
		for (int i = 0; i < N; ++i) {
			if (A[i] % 2 == 0) {
				sum += A[i];
			}
		}
		cout << sum << "\n";
	} else if (t == 6) {
		for (int x : A) {
			char c = 'a' + x % 26;
			cout << c;
		}
		cout << "\n";
	} else {
		deque<bool> vst(N);
		int i = 0;
		vst[0] = true;
		while (true) {
			i = A[i];
			if (i < 0 || i >= N) {
				cout << "Out\n";
			} else if (i == N - 1) {
				cout << "Done\n";
			} else if (vst[i]) {
				cout << "Cyclic\n";
			} else {
				vst[i] = true;
				continue;
			}
			break;
		}
	}
	return 0;
}

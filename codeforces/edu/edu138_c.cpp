#include <bits/stdc++.h>

using namespace std;

bool solve(deque<int> A, int K) {
	for (int i = K; i > 0; --i) {
		while (!A.empty() && A.back() > i) {
			A.pop_back();
		}
		if (A.empty()) {
			return false;
		}
		A.pop_back();
		while (!A.empty() && A.back() >= i) {
			A.pop_back();
		}
		if (A.size()) {
			A.pop_front();
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		deque<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		int ans{};
		for (; solve(A, ans + 1); ++ans);
		cout << ans << "\n";
	}
	return 0;
}

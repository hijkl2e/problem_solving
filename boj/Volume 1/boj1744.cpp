#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int ans{};
	while (A.size() > 1 && A[A.size() - 2] > 1) {
		ans += A[A.size() - 2] * A[A.size() - 1];
		A.pop_back();
		A.pop_back();
	}
	while (A.size() > 1 && A[1] < 1) {
		ans += A[0] * A[1];
		A.pop_front();
		A.pop_front();
	}
	ans += accumulate(A.begin(), A.end(), 0);
	cout << ans << "\n";
	return 0;
}

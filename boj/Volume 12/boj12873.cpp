#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = i + 1;
	}
	for (int i = 1; i < N; ++i) {
		int x = (1LL * i * i * i - 1) % A.size();
		rotate(A.begin(), A.begin() + x, A.end());
		A.pop_front();
	}
	cout << A.front() << "\n";
	return 0;
}

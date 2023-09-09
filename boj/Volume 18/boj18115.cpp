#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	deque<int> dq;
	for (int i = 1; i <= N; ++i) {
		int x = A[N - i];
		if (x == 1) {
			dq.push_front(i);
		} else if (x == 2) {
			dq.insert(dq.begin() + 1, i);
		} else {
			dq.push_back(i);
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << dq[i] << (i == N - 1 ? "\n": " ");
	}
	return 0;
}

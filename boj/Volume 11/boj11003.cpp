#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	deque<int> dq;
	for (int i = 0; i < N; ++i) {
		if (dq.size() && i - dq.front() == L) {
			dq.pop_front();
		}
		while (dq.size() && A[dq.back()] >= A[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
		cout << A[dq.front()] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}

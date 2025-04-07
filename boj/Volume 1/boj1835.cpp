#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<int> dq;
	for (int i = N; i > 0; --i) {
		dq.push_front(i);
		for (int j = 0; j < i; ++j) {
			dq.push_front(dq.back());
			dq.pop_back();
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << dq[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}

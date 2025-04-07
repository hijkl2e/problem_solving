#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<int> dq(N);
	for (int i = 0; i < N; ++i) {
		cin >> dq[i];
	}
	sort(dq.begin(), dq.end());
	int ans{};
	while (dq.size() > 1) {
		dq.pop_back();
		if (--dq.front() == 0) {
			dq.pop_front();
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}

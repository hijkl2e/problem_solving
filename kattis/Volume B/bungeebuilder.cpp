#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}
	stack<int> st1;
	stack<int> st2;
	int ans{};
	for (int i = 0; i < N; ++i) {
		while (st1.size() && st1.top() <= H[i]) {
			int x = st2.top();
			ans = max(ans, st1.top() - x);
			st1.pop();
			st2.pop();
			if (st2.size()) {
				st2.top() = min(st2.top(), x);
			}
		}
		if (st1.size()) {
			ans = max(ans, H[i] - st2.top());
		}
		st1.push(H[i]);
		st2.push(H[i]);
	}
	cout << ans << "\n";
	return 0;
}

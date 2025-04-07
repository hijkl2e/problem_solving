#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	queue<int> q;
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == 'B') {
			q.push(i);
		}
	}
	int ans{};
	for (int i = 0; i < S.size() && q.size(); ++i) {
		if (S[i] == 'C' && i > q.front()) {
			q.pop();
			++ans;
		}
	}
	for (int i = 0; i < S.size() && q.size(); ++i) {
		if (S[i] != 'A') {
			continue;
		}
		while (q.size() && i > q.front()) {
			q.pop();
		}
		if (q.size()) {
			q.pop();
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}

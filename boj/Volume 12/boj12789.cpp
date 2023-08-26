#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	queue<int> q;
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		q.push(x);
	}
	stack<int> st;
	bool yes = true;
	for (int i = 1; i <= N; ++i) {
		while ((st.empty() || st.top() != i) && q.size()) {
			st.push(q.front());
			q.pop();
		}
		if (st.top() == i) {
			st.pop();
		} else {
			yes = false;
			break;
		}
	}
	cout << (yes ? "Nice" : "Sad") << "\n";
	return 0;
}

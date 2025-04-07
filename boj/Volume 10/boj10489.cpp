#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	stack<int> st;
	while (N--) {
		int x{};
		cin >> x;
		if (st.size() && (st.top() + x) % 2 == 0) {
			st.pop();
		} else {
			st.push(x);
		}
	}
	cout << st.size() << "\n";
	return 0;
}

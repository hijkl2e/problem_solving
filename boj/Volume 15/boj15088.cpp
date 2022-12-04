#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	int x{};
	stack<int> st;
	while (K--) {
		string s;
		cin >> s;
		if (s == "undo") {
			int y{};
			cin >> y;
			while (y--) {
				x = st.top();
				st.pop();
			}
		} else {
			int y = stoi(s);
			y = (y % N + N) % N;
			st.push(x);
			x = (x + y) % N;
		}
	}
	cout << x << "\n";
	return 0;
}

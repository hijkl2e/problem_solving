#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	stack<int> st;
	int x{};
	vector<char> A;
	while (N--) {
		int y{};
		cin >> y;
		while (x < y) {
			st.push(++x);
			A.push_back('+');
		}
		if (st.size() && st.top() == y) {
			st.pop();
			A.push_back('-');
		} else {
			A.clear();
			break;
		}
	}
	if (A.empty()) {
		cout << "NO\n";
	} else {
		for (char c : A) {
			cout << c << "\n";
		}
	}
	return 0;
}

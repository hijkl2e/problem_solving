#include <bits/stdc++.h>

using namespace std;

string S;

int solve(int &p) {
	++p;
	if (S[p] == ')' || S[p] == ']') {
		return S[p++] == ')' ? 2 : 3;
	}
	int ret{};
	while (p < S.size()) {
		if (S[p] == ')' || S[p] == ']') {
			break;
		}
		ret += solve(p);
	}
	return (S[p++] == ')' ? 2 : 3) * ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	getline(cin, S);
	stack<char> st;
	bool flag{};
	for (char c : S) {
		if (c == '(' || c == '[') {
			st.push(c);
		} else if (st.size() && st.top() == (c == ')' ? '(' : '[')) {
			st.pop();
		} else {
			flag = true;
			break;
		}
	}
	flag |= st.size() > 0;
	if (flag) {
		cout << "0\n";
		return 0;
	}
	int ans{}, p{};
	while (p < S.size()) {
		ans += solve(p);
	}
	cout << ans << "\n";
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != ".") {
		stack<char> st;
		bool yes = true;
		for (char c : S) {
			if (c == '(' || c == '[') {
				st.push(c);
			} else if (c == ')' || c == ']') {
				if (st.size() && st.top() == (c == ')' ? '(' : '[')) {
					st.pop();
				} else {
					yes = false;
					break;
				}
			}
		}
		yes &= st.empty();
		cout << (yes ? "yes" : "no") << "\n";
	}
	return 0;
}

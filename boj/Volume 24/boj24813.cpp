#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, char> v2i{
		{'t', '|'}, {'j', '*'}, {'b', '$'}
	};
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		bool yes = true;
		stack<char> st;
		for (char c : S) {
			if (c == '.') {
				continue;
			} else if (c == 't' || c == 'j' || c == 'b') {
				if (st.size() && st.top() == v2i[c]) {
					st.pop();
				} else {
					yes = false;
					break;
				}
			} else {
				st.push(c);
			}
		}
		yes &= st.empty();
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}

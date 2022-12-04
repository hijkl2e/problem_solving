#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{};
	cin >> L;
	cin.ignore();
	string S;
	getline(cin, S);
	stack<char> st;
	int err = -1;
	for (int i = 0; i < L; ++i) {
		char c = S[i];
		if (c == ' ') {
			continue;
		} else if (c == '(' || c == '[' || c == '{') {
			st.push(c);
		} else {
			if (st.size() && abs(c - st.top()) < 3) {
				st.pop();
			} else {
				err = i;
				break;
			}
		}
	}
	if (err == -1) {
		cout << "ok so far\n";
	} else {
		cout << S[err] << " " << err << "\n";
	}
	return 0;
}

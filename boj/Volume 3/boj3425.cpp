#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int tc = 0;; ++tc) {
		vector<string> A;
		string S;
		while (cin >> S) {
			if (S == "END") {
				break;
			} else if (S == "NUM") {
				cin >> S;
			}
			A.push_back(S);
		}
		if (A.size() && A[0] == "QUIT") {
			break;
		}
		if (tc) {
			cout << "\n";
		}
		int N{};
		cin >> N;
		while (N--) {
			ll x{}, y{};
			cin >> x;
			stack<ll> st;
			st.push(x);
			bool yes = true;
			for (auto &cmd : A) {
				if (isdigit(cmd[0])) {
					st.push(stoi(cmd));
				} else if (cmd == "POP" || cmd == "INV" || cmd == "DUP") {
					if (st.empty()) {
						yes = false;
						break;
					}
					if (cmd == "POP") {
						st.pop();
					} else if (cmd == "INV") {
						st.top() *= -1;
					} else {
						st.push(st.top());
					}
				} else {
					if (st.size() < 2) {
						yes = false;
						break;
					}
					y = st.top(); st.pop();
					x = st.top(); st.pop();
					if (cmd == "SWP") {
						st.push(y);
						st.push(x);
						continue;
					} else if ((cmd == "DIV" || cmd == "MOD") && y == 0) {
						yes = false;
						break;
					}
					ll res{};
					if (cmd == "ADD") {
						res = x + y;
					} else if (cmd == "SUB") {
						res = x - y;
					} else if (cmd == "MUL") {
						res = x * y;
					} else if (cmd == "DIV") {
						res = x / y;
					} else {
						res = x % y;
					}
					if (abs(res) > INF) {
						yes = false;
						break;
					}
					st.push(res);
				}
			}
			if (yes && st.size() == 1) {
				cout << st.top() << "\n";
			} else {
				cout << "ERROR\n";
			}
		}
	}
	return 0;
}

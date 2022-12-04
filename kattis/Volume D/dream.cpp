#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<string, int> e2i;
	stack<string> st;
	while (N--) {
		char q{};
		cin >> q;
		if (q == 'E') {
			string E;
			cin >> E;
			e2i.insert({E, e2i.size()});
			st.push(E);
		} else if (q == 'D') {
			int R{};
			cin >> R;
			while (R--) {
				e2i.erase(st.top());
				st.pop();
			}
		} else {
			int K{};
			cin >> K;
			int idx1 = INF, idx2 = -1;
			while (K--) {
				string E;
				cin >> E;
				if (E[0] == '!') {
					E = E.substr(1);
					auto it = e2i.find(E);
					if (it == e2i.end()) {
						continue;
					}
					idx1 = min(idx1, it->second);
				} else {
					auto it = e2i.find(E);
					if (it == e2i.end()) {
						idx2 = INF;
					}
					idx2 = max(idx2, it->second);
				}
			}
			if (idx1 > idx2) {
				if (idx1 == INF) {
					cout << "Yes\n";
				} else {
					cout << (st.size() - idx1) << " Just A Dream\n";
				}
			} else {
				cout << "Plot Error\n";
			}
		}
	}
	return 0;
}

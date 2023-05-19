#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int sm{}, sc{}, si{};
		cin >> sm >> sc >> si;
		cin.ignore();
		string prog, in;
		getline(cin, prog);
		getline(cin, in);
		stack<int> st;
		vector<int> A(sc, -1);
		for (int i = 0; i < sc; ++i) {
			if (prog[i] == '[') {
				st.push(i);
			} else if (prog[i] == ']') {
				int x = st.top(); st.pop();
				A[i] = x, A[x] = i;
			}
		}
		vector<int> B(sm);
		int p{}, inp{}, lp = -1;
		for (int i = 0, t = 0; i < sc && t < 100000000; ++i, ++t) {
			if (prog[i] == '-') {
				B[p] = (B[p] + 255) % 256;
			} else if (prog[i] == '+') {
				B[p] = (B[p] + 1) % 256;
			} else if (prog[i] == '<') {
				p = (p + sm - 1) % sm;
			} else if (prog[i] == '>') {
				p = (p + 1) % sm;
			} else if (prog[i] == '[') {
				if (B[p] == 0) {
					i = A[i];
				}
			} else if (prog[i] == ']') {
				if (B[p]) {
					lp = max(lp, t < 50000000 ? -1 : i);
					i = A[i];
				}
			} else if (prog[i] == ',') {
				B[p] = inp == si ? 255 : in[inp++];
			}
		}
		if (lp == -1) {
			cout << "Terminates\n";
		} else {
			cout << "Loops " << A[lp] << " " << lp << "\n";
		}
	}
	return 0;
}

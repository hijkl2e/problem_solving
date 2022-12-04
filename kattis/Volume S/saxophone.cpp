#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		vector<int> A(8);
		deque<bool> B(8);
		for (char c : S) {
			int beg{}, end{};
			if (c == 'C') {
				beg = 2, end = 3;
			} else {
				beg = !isupper(c);
				end = ('G' - toupper(c) + 2) % 7 + 2;
			}
			for (int i = 0; i < 8; ++i) {
				bool flag = beg <= i && i < end;
				if (flag && !B[i]) {
					++A[i];
				}
				B[i] = flag;
			}
		}
		for (int i = 0; i < 8; ++i) {
			cout << A[i] << (i == 7 ? "\n" : i == 3 ? " 0 0 " : " ");
		}
	}
	return 0;
}

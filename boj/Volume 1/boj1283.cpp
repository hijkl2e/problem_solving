#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	deque<bool> A(26);
	while (N--) {
		string S;
		getline(cin, S);
		int p = -1;
		for (int k = 0; k < 2; ++k) {
			for (int i = 0; i < S.size() && p == -1; ++i) {
				if ((k || i == 0 || S[i - 1] == ' ') && isalpha(S[i]) && !A[tolower(S[i]) - 'a']) {
					A[tolower(S[i]) - 'a'] = true;
					p = i;
				}
			}
		}
		for (int i = 0; i < S.size(); ++i) {
			if (p == i) {
				cout << "[" << S[i] << "]";
			} else {
				cout << S[i];
			}
		}
		cout << "\n";
	}
	return 0;
}

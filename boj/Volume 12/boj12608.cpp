#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9
	};
	vector<int> B{
		1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4
	};
	map<char, int> c2a{{' ', 0}};
	map<char, int> c2b{{' ', 1}};
	for (int i = 0; i < 26; ++i) {
		c2a['a' + i] = A[i];
		c2b['a' + i] = B[i];
	}
	int T{};
	cin >> T;
	cin.ignore();
	for (int tc = 1; tc <= T; ++tc) {
		string S;
		getline(cin, S);
		cout << "Case #" << tc << ": ";
		for (int i = 0; i < S.size(); ++i) {
			if (i && c2a[S[i - 1]] == c2a[S[i]]) {
				cout << " ";
			}
			int a = c2a[S[i]];
			int b = c2b[S[i]];
			for (int j = 0; j < b; ++j) {
				cout << a;
			}
		}
		cout << "\n";
	}
	return 0;
}

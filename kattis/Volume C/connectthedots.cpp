#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, int> c2i;
	for (char c = '0'; c <= '9'; ++c) {
		c2i[c] = c2i.size();
	}
	for (char c = 'a'; c <= 'z'; ++c) {
		c2i[c] = c2i.size();
	}
	for (char c = 'A'; c <= 'Z'; ++c) {
		c2i[c] = c2i.size();
	}
	c2i['.'] = c2i['|'] = c2i['-'] = c2i['+'] = 1e9;
	vector<string> A;
	string S;
	while (true) {
		getline(cin, S);
		if (cin && S.size()) {
			A.push_back(S);
			continue;
		}
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < A[i].size(); ++j) {
				for (int k = i + 2; k < A.size(); ++k) {
					if (abs(c2i[A[i][j]] - c2i[A[k][j]]) == 1) {
						for (int l = i + 1; l < k; ++l) {
							A[l][j] = A[l][j] == '.' ? '|' : A[l][j] == '-' ? '+' : A[l][j];
						}
					}
				}
				for (int k = j + 2; k < A[i].size(); ++k) {
					if (abs(c2i[A[i][j]] - c2i[A[i][k]]) == 1) {
						for (int l = j + 1; l < k; ++l) {
							A[i][l] = A[i][l] == '.' ? '-' : A[i][l] == '|' ? '+' : A[i][l];
						}
					}
				}
			}
		}
		for (auto &s : A) {
			cout << s << "\n";
		}
		if (!cin) {
			break;
		}
		cout << "\n";
		A.clear();
	}
	return 0;
}

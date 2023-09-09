#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	getline(cin, S);
	istringstream iss(S);
	iss >> S;
	while (iss >> T) {
		T.pop_back();
		int p{};
		while (p < T.size() && isalpha(T[p])) {
			++p;
		}
		cout << S;
		for (int i = T.size() - 1; i >= p; --i) {
			if (T[i] == ']') {
				cout << "[]";
				--i;
			} else {
				cout << T[i];
			}
		}
		cout << " ";
		for (int i = 0; i < p; ++i) {
			cout << T[i];
		}
		cout << ";\n";
	}
	return 0;
}

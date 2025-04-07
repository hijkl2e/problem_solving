#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	getline(cin, S);
	getline(cin, T);
	while (S.size() < T.size()) {
		char c = T.back();
		T.pop_back();
		if (c == 'B') {
			reverse(T.begin(), T.end());
		}
	}
	cout << (S == T) << "\n";
	return 0;
}

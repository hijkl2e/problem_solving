#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int R{}, C{};
	for (int i = 1; i * i <= S.size(); ++i) {
		if (S.size() % i == 0) {
			R = S.size() / i;
			C = i;
		}
	}
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < S.size(); j += C) {
			cout << S[i + j];
		}
	}
	cout << "\n";
	return 0;
}

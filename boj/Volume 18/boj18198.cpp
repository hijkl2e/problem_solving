#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int A{}, B{};
	for (int i = 0; i < S.size(); i += 2) {
		int x = S[i + 1] - '0';
		if (S[i] == 'A') {
			A += x;
		} else {
			B += x;
		}
	}
	cout << (A > B ? 'A' : 'B') << "\n";
	return 0;
}

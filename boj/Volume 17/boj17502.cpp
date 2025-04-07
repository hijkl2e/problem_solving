#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	for (int i = 0, j = N - 1; i <= j; ++i, --j) {
		if (S[i] != '?') {
			S[j] = S[i];
		} else if (S[j] != '?') {
			S[i] = S[j];
		} else {
			S[i] = S[j] = 'a';
		}
	}
	cout << S << "\n";
	return 0;
}

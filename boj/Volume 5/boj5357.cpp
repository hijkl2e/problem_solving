#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	while (N--) {
		string S;
		getline(cin, S);
		for (int i = 0; i < S.size(); ++i) {
			if (i + 1 < S.size() && S[i] == S[i + 1]) {
				continue;
			}
			cout << S[i];
		}
		cout << "\n";
	}
	return 0;
}

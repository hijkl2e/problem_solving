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
	bool flag = true;
	for (int i = 0; i < 2 * N - 1; ++i) {
		if (S[i] == S[i + 1]) {
			flag = false;
			break;
		}
	}
	cout << (flag ? "Yes" : "No") << "\n";
	return 0;
}

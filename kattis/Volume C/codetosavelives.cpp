#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string line;
	getline(cin, line);
	int T = stoi(line);
	while (T--) {
		int A{}, B{}, x{};
		getline(cin, line);
		istringstream iss(line);
		while (iss >> x) {
			A = 10 * A + x;
		}
		getline(cin, line);
		iss = istringstream(line);
		while (iss >> x) {
			B = 10 * B + x;
		}
		string ans = to_string(A + B);
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}

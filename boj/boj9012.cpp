#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		bool yes = true;
		int cnt{};
		for (char c : S) {
			cnt += c == '(' ? 1 : -1;
			if (cnt == -1) {
				break;
			}
		}
		yes &= cnt == 0;
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}

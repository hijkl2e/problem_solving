#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	istringstream iss(S);
	int ans{};
	while (getline(iss, S, ';')) {
		if (S.find("-") == -1) {
			++ans;
			continue;
		}
		int idx = S.find("-");
		int x = stoi(S.substr(0, idx));
		int y = stoi(S.substr(idx + 1));
		ans += y - x + 1;
	}
	cout << ans << "\n";
	return 0;
}

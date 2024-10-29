#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	int ans{};
	while (N--) {
		string S;
		getline(cin, S);
		if (S.find("01") != -1 || S.find("OI") != -1) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}

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
	int ans{}, idx = -4;
	while ((idx = S.find("pPAp", idx + 4)) != -1) {
		++ans;
	}
	cout << ans << "\n";
	return 0;
}

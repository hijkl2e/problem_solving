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
	int ans = accumulate(S.begin(), S.end(), 0) - S.size() * '0';
	cout << ans << "\n";
	return 0;
}

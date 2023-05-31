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
	int ans = N - max<int>(count(S.begin(), S.end(), 'L') / 2 - 1, 0);
	cout << ans << "\n";
	return 0;
}

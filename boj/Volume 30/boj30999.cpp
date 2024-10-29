#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	int ans{};
	while (N--) {
		string S;
		getline(cin, S);
		if (count(S.begin(), S.end(), 'O') > M / 2) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}

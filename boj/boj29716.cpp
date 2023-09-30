#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int J{}, N{};
	cin >> J >> N;
	cin.ignore();
	int ans{};
	while (N--) {
		string S;
		getline(cin, S);
		int sum{};
		for (char c : S) {
			sum += isupper(c) ? 4 : c == ' ' ? 1 : 2;
		}
		if (sum <= J) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	while (N--) {
		string s;
		cin >> s;
		int x = stoi(s.substr(2));
		if (x <= 90) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}

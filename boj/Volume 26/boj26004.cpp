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
	vector<int> freq(26);
	for (char c : S) {
		++freq[c - 'A'];
	}
	int ans = 1e9;
	string hiarc = "HIARC";
	for (char c : hiarc) {
		ans = min(ans, freq[c - 'A']);
	}
	cout << ans << "\n";
	return 0;
}

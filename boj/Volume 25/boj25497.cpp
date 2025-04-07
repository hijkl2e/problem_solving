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
	int ans{}, cnt1{}, cnt2{};
	for (char c : S) {
		if (c == 'L') {
			++cnt1;
			continue;
		} else if (c == 'S') {
			++cnt2;
			continue;
		}
		if ((c == 'R' && cnt1-- == 0) || (c == 'K' && cnt2-- == 0)) {
			break;
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}

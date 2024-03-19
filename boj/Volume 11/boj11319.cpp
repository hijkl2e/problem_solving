#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string vowel = "AEIOUaeiou";
	int N{};
	cin >> N;
	cin.ignore();
	while (N--) {
		string S;
		getline(cin, S);
		int cnt1{}, cnt2{};
		for (char c : S) {
			if (isalpha(c)) {
				if (vowel.find(c) == -1) {
					++cnt1;
				} else {
					++cnt2;
				}
			}
		}
		cout << cnt1 << " " << cnt2 << "\n";
	}
	return 0;
}

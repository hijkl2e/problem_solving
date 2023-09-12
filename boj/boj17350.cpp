#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	bool yes{};
	while (N--) {
		string s;
		getline(cin, s);
		if (s == "anj") {
			yes = true;
			break;
		}
	}
	cout << (yes ? "뭐야;" : "뭐야?") << "\n";
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	while (N--) {
		string S;
		getline(cin, S);
		cout << (6 <= S.size() && S.size() <= 9 ? "yes" : "no") << "\n";
	}
	return 0;
}

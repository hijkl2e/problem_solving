#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string T = "Simon says";
	while (N--) {
		string S;
		getline(cin, S);
		if (S.size() > 10 && equal(S.begin(), S.begin() + 10, T.begin(), T.end())) {
			cout << S.substr(10) << "\n";
		}
	}
	return 0;
}

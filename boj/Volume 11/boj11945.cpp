#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	while (N--) {
		string S;
		getline(cin, S);
		reverse(S.begin(), S.end());
		cout << S << "\n";
	}
	return 0;
}

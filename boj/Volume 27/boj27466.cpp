#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	string S;
	getline(cin, S);
	while (S.size()) {
		char c = S.back();
		if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
			S.pop_back();
		} else {
			break;
		}
	}
	if (S.empty()) {
		cout << "NO\n";
		return 0;
	}
	char last = S.back();
	S.pop_back();
	int cnt{};
	while (S.size()) {
		char c = S.back();
		S.pop_back();
		if (c == 'A' && ++cnt == 2) {
			break;
		}
	}
	if (S.size() < M - 3) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << S.substr(0, M - 3) << "AA" << last << "\n";
	return 0;
}

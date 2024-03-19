#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	cin.ignore();
	string S;
	getline(cin, S);
	for (int i = 0; i < S.size(); i += K) {
		cout << S[i];
	}
	cout << "\n";
	return 0;
}

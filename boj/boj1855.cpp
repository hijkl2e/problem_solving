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
	for (int i = K; i < S.size(); i += 2 * K) {
		reverse(S.begin() + i, S.begin() + i + K);
	}
	for (int i = 0; i < K; ++i) {
		for (int j = i; j < S.size(); j += K) {
			cout << S[j];
		}
	}
	cout << "\n";
	return 0;
}

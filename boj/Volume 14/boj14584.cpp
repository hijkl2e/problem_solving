#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	while (true) {
		bool flag = false;
		for (auto &s : A) {
			if (S.find(s) != -1) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
		for (auto &c : S) {
			c = (c - 'a' + 1) % 26 + 'a';
		}
	}
	cout << S << "\n";
	return 0;
}

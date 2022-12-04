#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	cout << S << "\n";
	int N{};
	cin >> N;
	cin.ignore();
	cout << N << "\n";
	for (int i = 0; i < N; ++i) {
		getline(cin, S);
		istringstream iss(S);
		for (int j = 0; getline(iss, S, ','); ++j) {
			if (j) {
				S = S.substr(1);
				cout << ", ";
			}
			while (S.front() == ' ') {
				S.erase(S.begin());
			}
			while (S.back() == ' ') {
				S.erase(--S.end());
			}
			cout << S;
		}
		cout << "\n";
	}
	return 0;
}

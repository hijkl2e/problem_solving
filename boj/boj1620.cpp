#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		getline(cin, A[i]);
	}
	map<string, int> B;
	for (int i = 1; i <= N; ++i) {
		B[A[i]] = i;
	}
	while (M--) {
		string s;
		getline(cin, s);
		if (isdigit(s[0])) {
			cout << A[stoi(s)] << "\n";
		} else {
			cout << B[s] << "\n";
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	cout << "? 1000000000" << endl;
	string S;
	getline(cin, S);
	vector<int> ans(N + 1);
	for (int i = 0; i < N; ++i) {
		ans[i] = stoi(S.substr(S.size() - 9 * (i + 1), 9));
	}
	ans[N] = stoi(S.substr(0, S.size() % 9 ? S.size() % 9 : 9));
	cout << "! ";
	for (int i = 0; i <= N; ++i) {
		cout << ans[i] << (i == N ? "\n" : " ");
	}
	return 0;
}

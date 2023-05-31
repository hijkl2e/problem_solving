#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	for (int i = 1; i <= N; ++i) {
		string S;
		getline(cin, S);
		cout << i << ". " << S << "\n";
	}
	return 0;
}

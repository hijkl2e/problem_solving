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
	int ans{};
	while (N--) {
		string T;
		getline(cin, T);
		T += T;
		if (T.find(S) != -1) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}

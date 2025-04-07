#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cin.ignore();
		string S;
		getline(cin, S);
		bool yes{};
		map<string, int> s2i;
		for (int i = 0; i < N - 1; ++i) {
			auto it = s2i.insert({S.substr(i, 2), i}).first;
			if (it->second < i - 1) {
				yes = true;
				break;
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}

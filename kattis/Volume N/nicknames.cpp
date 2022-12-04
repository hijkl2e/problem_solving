#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	map<string, int> freq;
	while (N--) {
		string s;
		getline(cin, s);
		for (int i = 1; i <= s.size(); ++i) {
			++freq[s.substr(0, i)];
		}
	}
	int M{};
	cin >> M;
	cin.ignore();
	while (M--) {
		string s;
		getline(cin, s);
		cout << freq[s] << "\n";
	}
	return 0;
}

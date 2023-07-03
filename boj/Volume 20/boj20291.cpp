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
		string S;
		getline(cin, S);
		S = S.substr(S.find(".") + 1);
		++freq[S];
	}
	for (auto &p : freq) {
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}

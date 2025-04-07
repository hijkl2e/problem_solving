#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	string T;
	for (char c : S) {
		T += c;
		if (T.size() >= 4 && T.substr(T.size() - 4) == "PPAP") {
			T.erase(T.end() - 3, T.end());
		}
	}
	cout << (T == "P" ? "PPAP" : "NP") << "\n";
	return 0;
}

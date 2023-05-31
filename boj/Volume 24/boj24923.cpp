#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	cout << (S.substr(S.size() - 3) == "eh?" ? "Canadian!" : "Imposter!") << "\n";
	return 0;
}

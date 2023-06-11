#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string P;
	getline(cin, P);
	P.replace(P.find("*"), 1, "\\w*");
	regex r(P);
	while (N--) {
		string S;
		getline(cin, S);
		cout << (regex_match(S, r) ? "DA" : "NE") << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A{
		"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|",
		"|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['",
		"|_|", "\\/", "\\/\\/", "}{", "`/", "2"
	};
	string S;
	getline(cin, S);
	for (char c : S) {
		if (isalpha(c)) {
			cout << A[toupper(c) - 'A'];
		} else {
			cout << c;
		}
	}
	cout << "\n";
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A{
		"**** ** ** ****", "  *  *  *  *  *", "***  *****  ***", "***  ****  ****",
		"* ** ****  *  *", "****  ***  ****", "****  **** ****", "***  *  *  *  *",
		"**** ***** ****", "**** ****  ****"
	};
	map<string, int> h2i;
	for (int i = 0; i < 10; ++i) {
		h2i[A[i]] = i;
	}
	vector<string> S(5);
	for (int i = 0; i < 5; ++i) {
		getline(cin, S[i]);
	}
	int x{};
	for (int i = 0; i < S[0].size(); i += 4) {
		string s;
		for (int j = 0; j < 5; ++j) {
			s += S[j].substr(i, 3);
		}
		auto it = h2i.find(s);
		if (it == h2i.end()) {
			x = -1;
			break;
		}
		x = 10 * x + it->second;
	}
	cout << (x == -1 || x % 6 ? "BOOM!!" : "BEER!!") << "\n";
	return 0;
}

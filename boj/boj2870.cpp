#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A;
	while (N--) {
		string S;
		getline(cin, S);
		for (int i = 0, j = 1; i < S.size(); i = j++) {
			if (!isdigit(S[i])) {
				continue;
			}
			while (j < S.size() && isdigit(S[j])) {
				++j;
			}
			while (i + 1 < j && S[i] == '0') {
				++i;
			}
			A.push_back(S.substr(i, j - i));
		}
	}
	sort(A.begin(), A.end(), [](string &s1, string &s2) {
		return s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2);
	});
	for (auto &s : A) {
		cout << s << "\n";
	}
	return 0;
}

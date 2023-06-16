#include <bits/stdc++.h>

using namespace std;

using si = pair<string, int>;

vector<int> get_sa(string &S) {
	vector<si> A(S.size());
	for (int i = 0; i < A.size(); ++i) {
		A[i] = {S.substr(i), i};
	}
	sort(A.begin(), A.end());
	vector<int> sa(A.size());
	for (int i = 0; i < sa.size(); ++i) {
		sa[i] = A[i].second;
	}
	return sa;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> sa = get_sa(S);
	bool yes{};
	for (int i = 0; i < sa.size(); ++i) {
		int x = sa[i];
		if (S[x] == 'a') {
			continue;
		}
		--S[x];
		if (get_sa(S) == sa) {
			yes = true;
			break;
		}
		++S[x];
	}
	cout << yes << "\n";
	return 0;
}

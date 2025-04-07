#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A(26);
	for (char c : S) {
		c = toupper(c);
		++A[c - 'A'];
	}
	int maxi = max_element(A.begin(), A.end()) - A.begin();
	char c = count(A.begin(), A.end(), A[maxi]) == 1 ? ('A' + maxi) : '?';
	cout << c << "\n";
	return 0;
}

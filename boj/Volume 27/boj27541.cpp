#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	if (S.back() == 'G') {
		S.pop_back();
	} else {
		S.push_back('G');
	}
	cout << S << "\n";
	return 0;
}

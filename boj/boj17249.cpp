#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int l = count(S.begin(), S.begin() + S.find('('), '@');
	int r = count(S.begin(), S.end(), '@') - l;
	cout << l << " " << r << "\n";
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a, b;
	cin >> a >> b;
	replace(a.begin(), a.end(), '6', '5');
	replace(b.begin(), b.end(), '6', '5');
	int minv = stoi(a) + stoi(b);
	replace(a.begin(), a.end(), '5', '6');
	replace(b.begin(), b.end(), '5', '6');
	int maxv = stoi(a) + stoi(b);
	cout << minv << " " << maxv << "\n";
	return 0;
}

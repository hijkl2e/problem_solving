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
	int x = count(S.begin(), S.end(), '2');
	int y = N - x;
	cout << (x > y ? "2" : x < y ? "e" : "yee") << "\n";
	return 0;
}

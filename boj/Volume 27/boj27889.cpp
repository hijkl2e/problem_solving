#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, string> A{
		{"NLCS", "North London Collegiate School"},
		{"BHA", "Branksome Hall Asia"},
		{"KIS", "Korea International School"},
		{"SJA", "St. Johnsbury Academy"}
	};
	string S;
	getline(cin, S);
	cout << A[S] << "\n";
	return 0;
}

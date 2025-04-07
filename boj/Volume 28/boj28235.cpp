#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, string> A{
		{"SONGDO", "HIGHSCHOOL"}, {"CODE", "MASTER"},
		{"2023", "0611"}, {"ALGORITHM", "CONTEST"}
	};
	string S;
	getline(cin, S);
	cout << A[S] << "\n";
	return 0;
}

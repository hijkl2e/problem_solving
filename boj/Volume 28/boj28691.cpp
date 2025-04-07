#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, string> A{
		{'M', "MatKor"}, {'W', "WiCys"}, {'C', "CyKor"}, {'A', "AlKor"}, {'$', "$clear"}
	};
	char c{};
	cin >> c;
	cout << A[c] << "\n";
	return 0;
}

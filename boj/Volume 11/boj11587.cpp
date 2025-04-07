#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6,
		6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9
	};
	int N{};
	cin >> N;
	cin.ignore();
	map<string, int> freq;
	while (N--) {
		string s;
		getline(cin, s);
		for (auto &c : s) {
			c = A[c - 'a'] + '0';
		}
		++freq[s];
	}
	string s;
	getline(cin, s);
	cout << freq[s] << "\n";
	return 0;
}

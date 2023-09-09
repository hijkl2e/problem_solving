#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<int> A;
	for (int i = 1; i <= N; ++i) {
		string S;
		getline(cin, S);
		if (S == "1 2 3 4 5 1 2 3 4 5") {
			A.push_back(i);
		}
	}
	for (int x : A) {
		cout << x << "\n";
	}
	return 0;
}

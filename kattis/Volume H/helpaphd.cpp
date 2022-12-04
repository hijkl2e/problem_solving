#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		string S;
		cin >> S;
		if (S == "P=NP") {
			cout << "skipped\n";
			continue;
		}
		istringstream iss(S);
		int a{}, b{};
		char c{};
		iss >> a >> c >> b;
		cout << a + b << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A{
		"Give you up", "Let you down", "Run around and desert you",
		"Make you cry", "Say goodbye", "Tell a lie and hurt you"
	};
	string S;
	getline(cin, S);
	bool yes = find(A.begin(), A.end(), S) == A.end();
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}

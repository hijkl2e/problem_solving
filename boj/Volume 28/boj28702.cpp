#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A(3);
	for (int i = 0; i < 3; ++i) {
		getline(cin, A[i]);
	}
	int x{};
	for (int i = 0; i < 3; ++i) {
		if (isdigit(A[i][0])) {
			x = stoi(A[i]) + (3 - i);
			break;
		}
	}
	string ans;
	if (x % 3 == 0 && x % 5 == 0) {
		ans = "FizzBuzz";
	} else if (x % 3 == 0) {
		ans = "Fizz";
	} else if (x % 5 == 0) {
		ans = "Buzz";
	} else {
		ans = to_string(x);
	}
	cout << ans << "\n";
	return 0;
}

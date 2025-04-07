#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	string ans;
	if (S == "fdsajkl;" || S == "jkl;fdsa") {
		ans = "in-out";
	} else if (S == "asdf;lkj" || S == ";lkjasdf") {
		ans = "out-in";
	} else if (S == "asdfjkl;") {
		ans = "stairs";
	} else if (S == ";lkjfdsa") {
		ans = "reverse";
	} else {
		ans = "molu";
	}
	cout << ans << "\n";
	return 0;
}

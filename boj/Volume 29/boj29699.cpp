#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string smupc = "WelcomeToSMUPC";
	int N{};
	cin >> N;
	cout << smupc[(N - 1) % 14] << "\n";
	return 0;
}

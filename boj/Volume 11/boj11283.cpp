#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	cin >> S;
	int N = 4096 * ((S[0] & 255) - 234) + 64 * ((S[1] & 255) - 128) + ((S[2] & 255) - 128) - 3071;
	cout << N << "\n";
	return 0;
}

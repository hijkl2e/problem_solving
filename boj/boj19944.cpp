#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cout << (M < 3 ? "NEWBIE" : M <= N ? "OLDBIE" : "TLE") << "!\n";
	return 0;
}

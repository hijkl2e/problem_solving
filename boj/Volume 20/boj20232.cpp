#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	if (N == 1996 || N == 1997 || N == 2000 || N == 2007 || N == 2008 || N == 2013 || N == 2018) {
		cout << "SPbSU\n";
	} else if (N == 2006) {
		cout << "PetrSU, ITMO\n";
	} else {
		cout << "ITMO\n";
	}
	return 0;
}

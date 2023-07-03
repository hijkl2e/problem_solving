#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A{
		"aespa", "baekjoon", "cau", "debug", "edge", "firefox",
		"golang", "haegang", "iu", "java", "kotlin", "lol", "mips",
		"null", "os", "python", "query", "roka", "solvedac", "tod",
		"unix", "virus", "whale", "xcode", "yahoo", "zebra"
	};
	string S, T;
	getline(cin, S);
	for (int i = 0; i < S.size();) {
		int x = S[i] - 'a';
		if (S.substr(i, A[x].size()) == A[x]) {
			T += S[i];
			i += A[x].size();
		} else {
			T = "";
			break;
		}
	}
	if (T.size()) {
		cout << "It's HG!\n" << T << "\n";
	} else {
		cout << "ERROR!\n";
	}
	return 0;
}

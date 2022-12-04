#include <bits/stdc++.h>

using namespace std;

vector<string> A{
	"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
	"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
	"seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty",
	"sixty", "seventy", "eighty", "ninety"
};

string solve(int x) {
	string ret;
	if (x / 100) {
		ret += A[x / 100];
		ret += "hundred";
		x %= 100;
	}
	if (x < 20) {
		ret += A[x];
	} else {
		ret += A[x / 10 + 18];
		ret += A[x % 10];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> B(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, B[i]);
	}
	int sum = -1;
	for (int i = 0; i < N; ++i) {
		sum += B[i].size();
	}
	string ans;
	for (int i = 1;; ++i) {
		string res = solve(i);
		if (sum + res.size() == i) {
			ans = res;
			break;
		}
	}
	for (int i = 0; i < B.size(); ++i) {
		cout << (B[i] == "$" ? ans : B[i]) << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}

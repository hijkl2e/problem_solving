#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <x86intrin.h>

using namespace std;

template <size_t _Nw>
void sub(_Base_bitset<_Nw> &A, _Base_bitset<_Nw> &B) {
	for (int i = 0, c = 0; i < _Nw; ++i) {
		c = _subborrow_u64(c, A._M_w[i], B._M_w[i],
				reinterpret_cast<unsigned long long *>(&A._M_w[i]));
	}
}

template <size_t _Nb>
bitset<_Nb> operator-(bitset<_Nb> &A, bitset<_Nb> &B) {
	bitset<_Nb> C = A;
	sub(C, B);
	return C;
}

int lcs(const string &S, const string &T) {
	vector<bitset<50001>> A(26);
	for (int i = 0; i < T.size(); ++i) {
		A[T[i] - 'a'][i] = true;
	}
	bitset<50001> x, y;
	for (int i = 0; i < S.size(); ++i) {
		x = A[S[i] - 'a'] | y;
		y = x & ((x - (y << 1).set(0)) ^ x);
	}
	return y.count();
}

string erase(const string &S, char e) {
	string ret;
	for (char c : S) {
		if (c == e) {
			continue;
		}
		ret += c;
	}
	return ret;
}

deque<bool> sieve() {
	deque<bool> p(50001, true);
	p[0] = p[1] = false;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			for (int j = 2 * i; j < p.size(); j += i) {
				p[j] = false;
			}
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> p = sieve();
	string S, T;
	getline(cin, S);
	getline(cin, T);
	char X{}, Y{};
	cin >> X >> Y;
	S = erase(S, Y);
	T = erase(T, Y);
	int p1 = find(S.begin(), S.end(), X) - S.begin();
	int p2 = find(T.begin(), T.end(), X) - T.begin();
	int len = lcs(S.substr(0, p1), T.substr(0, p2)) + lcs(S.substr(p1), T.substr(p2));
	int ans = -1;
	for (int i = len; i > 1; --i) {
		if (p[i]) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}

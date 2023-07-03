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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	getline(cin, S);
	getline(cin, T);
	vector<bitset<50001>> A(26);
	for (int i = 0; i < T.size(); ++i) {
		A[T[i] - 'A'][i] = true;
	}
	bitset<50001> x, y;
	for (int i = 0; i < S.size(); ++i) {
		x = A[S[i] - 'A'] | y;
		y = x & ((x - (y << 1).set(0)) ^ x);
	}
	cout << y.count() << "\n";
	return 0;
}

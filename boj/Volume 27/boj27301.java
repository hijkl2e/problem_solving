import java.math.BigInteger;
import java.util.Scanner;

public class boj27301 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger N = sc.nextBigInteger();
		int K = sc.nextInt();
		BigInteger[] A = new BigInteger[1001];
		BigInteger[] B = new BigInteger[1001];
		BigInteger[] C = new BigInteger[1001];
		A[0] = B[0] = C[0] = BigInteger.ZERO;
		A[1] = B[1] = C[1] = BigInteger.ONE;
		for (int i = 2; i < A.length; ++i) {
			A[i] = A[i - 1].multiply(BigInteger.TEN);
			B[i] = A[i].multiply(BigInteger.valueOf(i));
			C[i] = C[i - 1].add(A[i]);
		}
		int len = 1;
		while (B[len].subtract(K == 0 ? C[len] : BigInteger.ZERO).compareTo(N) == -1) {
			++len;
		}
		N = N.subtract(B[len - 1]).add(K == 0 ? C[len - 1] : BigInteger.ZERO);
		int cnt = 0;
		StringBuilder sb = new StringBuilder();
		for (int i = len - 1; i >= 0; --i) {
			for (int j = i == len - 1 ? 1 : 0; j < 10; ++j) {
				BigInteger x = B[i].add(j == K ? A[i + 1] : BigInteger.ZERO);
				x = x.add(BigInteger.valueOf(cnt).multiply(A[i + 1]));
				if (N.compareTo(x) < 1) {
					sb.append(j);
					if (j == K) {
						++cnt;
					}
					break;
				}
				N = N.subtract(x);
			}
		}
		System.out.println(sb);
		sc.close();
	}
}

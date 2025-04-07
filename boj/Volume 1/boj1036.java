import java.math.BigInteger;
import java.util.Scanner;

public class boj1036 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String[] A = new String[N];
		for (int i = 0; i < N; ++i) {
			A[i] = sc.next();
		}
		int K = sc.nextInt();
		BigInteger[] B = new BigInteger[36];
		for (int i = 0; i < 36; ++i) {
			B[i] = BigInteger.ZERO;
		}
		BigInteger[] C = new BigInteger[N];
		for (int i = 0; i < N; ++i) {
			C[i] = BigInteger.ZERO;
			BigInteger x = BigInteger.ONE;
			for (int j = A[i].length() - 1; j >= 0; --j) {
				char c = A[i].charAt(j);
				int y = c >= 'A' ? (c - 'A' + 10) : (c - '0');
				B[y] = B[y].add(x);
				C[i] = C[i].add(BigInteger.valueOf(y).multiply(x));
				x = x.multiply(BigInteger.valueOf(36));
			}
		}
		for (int i = 0; i < 36; ++i) {
			B[i] = B[i].multiply(BigInteger.valueOf(35 - i));
		}
		BigInteger ans = BigInteger.ZERO;
		for (int i = 0; i < N; ++i) {
			ans = ans.add(C[i]);
		}
		while (K-- > 0) {
			int p = 0;
			for (int i = 0; i < 36; ++i) {
				if (B[p].compareTo(B[i]) < 0) {
					p = i;
				}
			}
			ans = ans.add(B[p]);
			B[p] = BigInteger.ZERO;
		}
		StringBuilder sb = new StringBuilder();
		while (ans.compareTo(BigInteger.ZERO) > 0 || sb.length() == 0) {
			int r = ans.remainder(BigInteger.valueOf(36)).intValue();
			char c = (char) (r < 10 ? (r + '0') : (r + 'A' - 10));
			sb.append(c);
			ans = ans.divide(BigInteger.valueOf(36));
		}
		sb.reverse();
		System.out.println(sb);
		sc.close();
	}
}

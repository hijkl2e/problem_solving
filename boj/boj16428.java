import java.math.BigInteger;
import java.util.Scanner;

public class boj16428 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger A = sc.nextBigInteger();
		BigInteger B = sc.nextBigInteger();
		BigInteger[] res = A.divideAndRemainder(B);
		if (res[1].signum() == -1) {
			if (B.signum() == 1) {
				res[1] = res[1].add(B);
				res[0] = res[0].subtract(BigInteger.ONE);
			} else {
				res[1] = res[1].subtract(B);
				res[0] = res[0].add(BigInteger.ONE);
			}
		}
		System.out.println(res[0]);
		System.out.println(res[1]);
		sc.close();
	}
}

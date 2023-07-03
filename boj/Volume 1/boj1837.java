import java.math.BigInteger;
import java.util.Scanner;

public class boj1837 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger K = sc.nextBigInteger();
		int L = sc.nextInt();
		int p = 0;
		for (int i = 2; i < L; ++i) {
			BigInteger r = K.remainder(BigInteger.valueOf(i));
			if (r.equals(BigInteger.ZERO)) {
				p = i;
				break;
			}
		}
		if (p > 0) {
			System.out.println("BAD " + p);
		} else {
			System.out.println("GOOD");
		}
		sc.close();
	}
}

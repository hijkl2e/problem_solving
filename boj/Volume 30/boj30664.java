import java.math.BigInteger;
import java.util.Scanner;

public class boj30664 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger ft = BigInteger.valueOf(42);
		while (sc.hasNextLine()) {
			BigInteger N = sc.nextBigInteger();
			if (N.signum() == 0) {
				break;
			} else if (N.remainder(ft).signum() == 0) {
				System.out.println("PREMIADO");
			} else {
				System.out.println("TENTE NOVAMENTE");
			}
		}
		sc.close();
	}
}

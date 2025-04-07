import java.math.BigDecimal;
import java.math.MathContext;
import java.util.Scanner;

public class boj15792 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigDecimal A = sc.nextBigDecimal();
		BigDecimal B = sc.nextBigDecimal();
		System.out.println(A.divide(B, new MathContext(1021)));
		sc.close();
	}
}

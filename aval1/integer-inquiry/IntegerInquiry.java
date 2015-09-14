import java.math.BigInteger;
import java.util.Scanner;
import java.util.ArrayList;

class Main {
    public static void main(String args[]) {
        ArrayList<BigInteger> nums = new ArrayList<>();
        Scanner s = new Scanner(System.in);

        while(true) {
            String line = s.next();
            BigInteger num = new BigInteger(line);
            if(num.equals(BigInteger.ZERO))
                break;

            nums.add(num);
        }

        BigInteger result = BigInteger.ZERO;
        for(BigInteger num : nums) {
            result = result.add(num);
        }

        System.out.println(result.toString());
    }
}

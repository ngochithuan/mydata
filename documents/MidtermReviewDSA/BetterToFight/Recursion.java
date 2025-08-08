public class Recursion {
    public static int fac(int n) {
        int res = 1;
        while (n >= 1) {
            res = res * n;
            n--;
        }
        return res;
    }

    // 2. Write a program to Print Fibonacci Series in Java using Recursion?
    // (solution)
    public static void fib(int n) {
        if (n == 0) {
            System.out.println(0);
        }
        if (n == 1) {
            System.out.println(1);
        } else {
            System.out.println((n - 1) + (n - 2));
            fib(n - 1);
        }

    }

    // 3. Write a program to reverse String in Java using Recursion? (solution)
    public static String reverseString(String str) {
        String res = "";
        int i = str.length() - 1;
        while (i >= 0) {
            res = res + str.charAt(i);
            i--;
        }
        return res;
    }

    // Write a countDown(int number) method in Java using Recursion which prints
    // countdown till zero to console, like count(3) should print 3 2 1 0
    public static void countDown(int number) {
        while (number >= 0) {
            System.out.print(number + " ");
            number--;
        }
    }

    public static void main(String[] args) {
        System.out.println(fac(6));
        System.out.println(reverseString("NgoChiThuan"));
        countDown(12);
    }
}

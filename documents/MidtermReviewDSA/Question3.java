import java.util.Stack;

public class Question3 {
    private static boolean isNumber(String str) {
        return str.matches("0|([1-9][0-9]*)");
    }

    public static int calculate(String[] expression) {
        Stack<Integer> stack = new Stack<Integer>();
        for (int i = 0; i < expression.length; i++) {
            if (isNumber(expression[i])) {
                stack.push(Integer.parseInt(expression[i]));
            } else {
                int a = stack.pop();
                int b = stack.pop();
                if (expression[i] == "+") {
                    stack.push(b + a);
                }
                if (expression[i] == "-") {
                    stack.push(b - a);
                }
            }
        }
        return stack.peek();
    }

    public static void main(String[] args) {
        String[] expression = { "3", "4", "+", "2", "1", "+", "-" };
        System.out.println(calculate(expression));
    }
}

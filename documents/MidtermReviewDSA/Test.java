public class Test {
    public static void main(String[] args) {
        CharLinkedList charll = new CharLinkedList();
        charll.addFirst('0');
        charll.addFirst('1');
        charll.addFirst('2');
        charll.addFirst('3');
        charll.addFirst('1');

        charll.print();
        System.out.println(charll.addAfterFirstKey('7', '2'));
        charll.print();
        System.out.println(charll.largestCharPosition());
    }
}

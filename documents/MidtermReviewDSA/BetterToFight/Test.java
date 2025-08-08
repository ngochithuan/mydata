public class Test {
    public static void main(String[] args) {
        MyLinkedList list = new MyLinkedList();

        Node d = new Node(4, null);
        Node c = new Node(3, d);
        Node b = new Node(2, c);
        Node a = new Node(1, b);
        list.setHead(a);

        list.addFirst(0);
        list.addFirst(2);
        list.addFirst(2);

        list.addLast(7);
        list.print();
        // System.out.println(list.getTail().getData());
        System.out.println(list.size());
        System.out.println(list.sumEven());
        System.out.println(list.countKey(4));

        System.out.println("-----------");

        MyLinkedList l = new MyLinkedList();
        l.addFirst(9);
        l.addFirst(7);
        l.addFirst(5);
        l.addFirst(2);

        l.print();

    }
}

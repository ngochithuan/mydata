public class MyLinkedList implements ListInterface {
    private Node head = null;
    private Node tail;

    public Node getHead() {
        return this.head;
    }

    public void setHead(Node head) {
        this.head = head;
    }

    public Node getTail() {
        Node temp = head;
        while (temp != null) {
            if (temp.getNext().getNext() == null) {
                return temp.getNext();
            }
            temp = temp.getNext();
        }
        return null;
    }

    public void setTail(Node tail) {
        this.tail = tail;
    }

    public void print() {
        if (head == null) {
            System.out.println("This linked list is empty!");
        } else {
            Node temp = head;
            while (temp != null) {
                System.out.print(temp.getData() + " -> ");
                temp = temp.getNext();
            }
            System.out.print("null\n");
        }
    }

    public int size() {
        if (head == null) {
            return 0;
        }
        int count = 0;
        Node node = head;
        while (node != null) {
            count++;
            node = node.getNext();
        }
        return count;
    }

    public int sumEven() {
        int sum = 0;
        Node node = head;
        while (node != null) {
            if (node.getData() % 2 == 0)
                sum += node.getData();
            node = node.getNext();
        }
        return sum;
    }

    public int countKey(int k) {
        int count = 0;
        Node node = head;
        while (node != null) {
            if (node.getData() == k)
                count++;
            node = node.getNext();
        }
        return count;
    }

    public void addFirst(int x) {
        head = new Node(x, head);

    }

    public void addLast(int x) {
        Node newNode = new Node(x, null);
        getTail().setNext(newNode);
        tail = newNode;
    }
}

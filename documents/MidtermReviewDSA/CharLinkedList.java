public class CharLinkedList implements ListInterface {
    private Node head = null;

    public void print() {
        if (head == null) {
            System.out.println("Empty!");
        }
        Node node = head;
        while (node != null) {
            System.out.print(node.getData() + " ");
            node = node.getNext();
        }
        System.out.println();
    }

    public Node getHead() {
        return this.head;
    }

    public void addFirst(char data) {
        head = new Node(data, head);
    }

    public boolean addAfterFirstKey(char data, char x) {
        Node node = head;
        while (node != null) {
            if (node.getData() == x) {
                node.setNext(new Node(data, node.getNext()));
                return true;
            }

            node = node.getNext();
        }
        return false;
    }

    public int largestCharPosition() {
        if (head == null) {
            return -1;
        }
        int index = 0;
        int maxIndex = 0;
        Node node = head;
        char max = node.getData();
        while (node != null) {
            if (node.getData() > max) {
                max = node.getData();
                maxIndex = index;
            }
            node = node.getNext();
            index++;
        }
        return maxIndex;
    }
}

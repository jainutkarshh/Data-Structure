//detect wheater a linked list has a cycle in it or not
import java.util.HashSet;
class node{
        int data;
        node next;
        node(int x){
            data=x;
            next=null;
        }
    }
public class cyclell {
    static boolean hasCycle(node head){
        HashSet<node> set = new HashSet<>();
        while(head != null){
            if(set.contains(head))
                return true;
            set.add(head);
            head = head.next;
        }
        return false;
    }
    public static void main(String[] args) {
        node head=new node(10);
        head.next=new node(20);
        head.next.next=new node(30);
        head.next.next.next=new node(40);
        head.next.next.next.next=head.next; //creating a cycle here for testing

        if(hasCycle(head)){
            System.out.println("Linked list has a cycle");
        } else {
            System.out.println("Linked list has no cycle");
        }
    }

}

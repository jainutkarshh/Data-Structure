//accept 2 linkedlist of integer from user and determine whether the intersect or not .if they intersect display the intersecting node 

class node{
    int data;
    node next;
    node (int no){
        data=no;
        next=null;
    }
}
public class intersectll {
    public static void main(String[] args) {
        node head1= new node(10);
        head1.next=new node(20);
        head1.next.next=new node(30);
        head1.next.next.next=new node(40);
        head1.next.next.next.next=new node(50);

        node head2=new node(5);
        head2.next = new node(15);
        head2.next.next=head1.next.next.next; // intersecting at node with data 40
        //note if above statement is commented no intersection will occur

        node intersect=checknodeintersection(head1,head2);
        if (intersect == null){
            System.out.println("no intersecting node found");
        } else {
            System.out.println("intersecting node found with data: " + intersect.data);
        }

    }
    static node checknodeintersection(node head1, node head2){
        node p1,p2;
        p1=head1;
        p2=head2;
        //traverse both p1 &p2 in respctive lls andonce done let them continue traversing the other ll.this should be done until they meet or both reach null
        while(p1 != p2){
            if(p1==null){
                p1=head2;
            }else{
                p1=p1.next;
            }
            if(p2==null){
                p2=head1;
            }else{
                p2=p2.next;
            }
        }
        return p1;
    }
}

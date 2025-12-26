// given a linked list of integer values , Accept an int value from the user and rotate the ;; from right using ll .
// l=[10,20,30,40,50] k=1=>[50,10,20,30,40]
//k=2=>[40,50,10,20,30]

import java.util.LinkedList;
public class linkedlist {   
public static void main(String[] args) {
    LinkedList<Integer> list = new LinkedList<>();
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);

    System.out.println("Original List: " + list);
    int k=2;
    k=k % list.size(); 
    if(k != 0){
        LinkedList<Integer> l = rotateLL(list,k);
        System.out.println("Rotated List: " + l);
    }
}
    static LinkedList<Integer> rotateLL(LinkedList<Integer> list, int k){
        for(int i=0;i<k;i++){
            list.add(0,list.get(list.size()-1));
            list.remove(list.size()-1);
        }
        return list;
    }

}
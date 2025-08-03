import java.util.Arrays;
import java.util.Scanner;
public class ArrayList {
     private int[] data;
     private int count;
     public ArrayList() {
          data = new int[10];
          count = 0;
     }
     public void add(int value) {
          if (count == data.length) {
               data = Arrays.copyOf(data, data.length * 2);
          }
          data[count++] = value;
     }
     public int get(int index) {
          if (index < 0 || index >= count) throw new IndexOutOfBoundsException("Invalid index");
          return data[index];
     }
     public void set(int index, int value) {
          if (index < 0 || index >= count) throw new IndexOutOfBoundsException("Invalid index");
          data[index] = value;
     }
     public void remove(int index) {
          if (index < 0 || index >= count) throw new IndexOutOfBoundsException("Invalid index");
          for (int i = index; i < count - 1; i++) {
               data[i] = data[i + 1];
          }
          count--;
     }
     public int size() {
          return count;
     }
     public String toString() {
          StringBuilder sb = new StringBuilder("[");
          for (int i = 0; i < count; i++) {
               sb.append(data[i]);
               if (i < count - 1) sb.append(", ");
          }
          sb.append("]");
          return sb.toString();
     }
          
          

     public void sort() {
          Arrays.sort(data, 0, count);
     }
     public void clear() {
          count = 0;
     }
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          ArrayList list = new ArrayList();
          System.out.print("How many elements to add? ");
          int n = sc.nextInt();
          System.out.println("Enter " + n + " elements:");
          for (int i = 0; i < n; i++) {
               int val = sc.nextInt();
               list.add(val);
          }
          System.out.println("List after add(): " + list);
          System.out.print("Enter index to get: ");
          int getIndex = sc.nextInt();
          try {
               System.out.println("Element at index " + getIndex + ": " + list.get(getIndex));
          }  
          catch (IndexOutOfBoundsException e) {
               System.out.println(e.getMessage());
          }
          System.out.print("Enter index to set: ");
          int setIndex = sc.nextInt();
          System.out.print("Enter new value: ");
          int newValue = sc.nextInt();
          try {
               list.set(setIndex, newValue);
               System.out.println("List after set(): " + list);
          }
          catch (IndexOutOfBoundsException e) {
               System.out.println(e.getMessage());
          }
          System.out.print("Enter index to remove: ");
          int removeIndex = sc.nextInt();
          try {
               list.remove(removeIndex);
               System.out.println("List after remove(): " + list);
          } 
          catch (IndexOutOfBoundsException e) {
               System.out.println(e.getMessage());
          }
          System.out.println("Current size of list: " + list.size());
          System.out.println("List (toString): " + list.toString());
          list.sort();
          System.out.println("List after sort(): " + list);
          list.clear();
          System.out.println("List after clear(): " + list);
          sc.close();
     }
}

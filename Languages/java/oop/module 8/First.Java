class A {
     int x;
     public A() {
          x = 0;
     }
     public A(int x) {
          this.x = x;
     }
     public int getX() {
          return x + 10;
     }
}
class B extends A {
     int x = 20;
     public B() {
          super(50); 
     }
     public void displayAX() {
          System.out.println("x of class A: " + super.x);
     }
     public void callGetXofA() {
          System.out.println("getX() of class A: " + super.getX());
     }
     @Override
     public int getX() {
        return x + 10;
    }
}
public class First {
     public static void main(String[] args) {
          B obj = new B();
          obj.displayAX(); 
          obj.callGetXofA();    
          System.out.println("getX() of class B: " + obj.getX());  
     }
}

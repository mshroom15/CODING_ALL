public class prob7 {
    static int staticVar = 10;
    static int anotherStaticVar = 30;
    int nonStaticVar = 20;
    
    static void staticMethod() {
        System.out.println("This is a static method");
    }
    
    void nonStaticMethod() {
        System.out.println("This is a non-static method");
    }
    
    static void demonstrateStaticAccess() {
        System.out.println("=== Static Method Access Demonstration ===");
        
        System.out.println("Accessing static variable: " + staticVar);
        
        staticMethod();
        
        prob7 obj = new prob7();
        System.out.println("Accessing non-static variable through object: " + obj.nonStaticVar);
        obj.nonStaticMethod();
    }
    
    public static void main(String[] args) {
        demonstrateStaticAccess();
    }
}
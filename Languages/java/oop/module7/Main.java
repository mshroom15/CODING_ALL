class Singleton {
    private static Singleton instance;
    
    private Singleton() {
        
    }
    
    public static Singleton getInstance() {
        if (instance == null) {
            instance = new Singleton();
        }
        return instance;
    }
    
    public void showMessage() {
        System.out.println("Hello from Singleton instance!");
    }
}

public class Main {
    public static void main(String[] args) {
        Singleton singleton1 = Singleton.getInstance();
        Singleton singleton2 = Singleton.getInstance();
        System.out.println("Are both instances same? " + (singleton1 == singleton2));
        singleton1.showMessage();
        singleton2.showMessage();
    }
}
public class singleton {
    // Private static instance
    private static singleton instance;
    
    // Private constructor to prevent instantiation
    private singleton() {
        // Initialization code here
    }
    
    // Public method to get the instance
    public static singleton getInstance() {
        if (instance == null) {
            instance = new singleton();
        }
        return instance;
    }
    
    // Example method
    public void showMessage() {
        System.out.println("Hello from Singleton!");
    }
    
    // Main method
    public static void main(String[] args) {
        singleton obj = singleton.getInstance();
        obj.showMessage();
    }
}

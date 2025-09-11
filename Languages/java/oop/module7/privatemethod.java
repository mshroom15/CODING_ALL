class PrivateTest {
    private int data;

    public PrivateTest(int data) {
        this.data = data;
    }

    private void printData() {
        System.out.println("Private method called. Data is: " + data);
    }
    public void showData() {
        printData();
    }
}

public class privatemethod {
    public static void main(String[] args) {
        PrivateTest obj = new PrivateTest(100); 
        obj.showData();
    }
}
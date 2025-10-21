interface AI {
    void PrintA();
}

interface BI {
    void PrintB();
}

interface CI {
    void PrintC();
}

class A implements AI {
    @Override
    public void PrintA() {
        System.out.println("PrintA method in class A");
    }
}

class B extends A implements BI {
     @Override
    public void PrintB() {
        System.out.println("PrintB method in class B");
    }
}

class C extends B implements CI {
    @Override
    public void PrintC() {
        System.out.println("PrintC method in class C");
    }
}

public class intrfc {
    public static void main(String[] args) {
        C obj = new C();
        obj.PrintA();
        obj.PrintB();
        obj.PrintC();
    }
}

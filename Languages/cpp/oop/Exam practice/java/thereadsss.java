class theread1 extends Thread {
    public void run(){
        for(int i=1; i<=10;i++){
            System.out.println("video is playing"+ Thread.currentThread().getName());
            
        }
    }

    
}
class theread2 extends Thread {
    public void run(){
        for(int i=1; i<=10;i++){
            System.out.println("music is playing"+ Thread.currentThread().getName());
            
        }
    }
}

class theread3 extends Thread {
    public void run(){
        for(int i=1; i<=10;i++){
            System.out.println("Timer is playing"+ Thread.currentThread().getName());
            
        }
    }
}
public class thereadsss{
    public static void main(String[] arg){
        theread1 t1 = new theread1();
        theread2 t2 = new theread2();
        theread3 t3 = new theread3();
        t1.start();
        t2.start();
        t3.start();


    }
}


  

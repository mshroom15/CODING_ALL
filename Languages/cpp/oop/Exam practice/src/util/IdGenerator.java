package util;
 import java.util.concurrent.atomic.AtomicInteger;
 public  class IdGenerator{
    private static AtomicInteger id = new AtomicInteger(1000);
    public static int next(){
        return id.getAndIncrement();}
    
 };
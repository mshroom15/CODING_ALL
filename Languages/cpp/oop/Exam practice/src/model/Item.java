package model;
import java.io.Serializable;
public class Item implements Serializable {
    private static final long serialVersionUID = 1L;
    private int id;
    private String title;
    private boolean available;

    public Item(int id, String title) {
        this.id = id;
        this.title = title;
        this.available = true;
    }
    public Item(String title) {
        this(-1, title);
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return title;
    }
    public boolean isAvailable() {
        return available;
    }
    public void setAvailable(boolean available) {
        this.available = available;
    }
    public void setId(int id) {
        this.id = id;
    }
    public void setTitle(String title) {
        this.title = title;
    }
}

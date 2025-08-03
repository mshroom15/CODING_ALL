public class Arraylistclass {
    private int[] array;
    private int size;

    public Arraylistclass() {
        array = new int[10];
        size = 0;
    }

    public void add(int value) {
        if (size == array.length) {
            resize();
        }
        array[size++] = value;
    }

    private void resize() {
        int[] newArray = new int[array.length * 2];
        System.arraycopy(array, 0, newArray, 0, array.length);
        array = newArray;
    }

    public int get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        return array[index];
    }

    public int size() {
        return size;
    }
    public void clear() {
        array = new int[10];
        size = 0;
    }
    public void remove(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        for (int i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
    }
    public void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        array[index] = value;
    }
    public int sort() {
        int[] sortedArray = new int[size];
        System.arraycopy(array, 0, sortedArray, 0, size);
        java.util.Arrays.sort(sortedArray);
        return sortedArray[0]; // Return the first element of the sorted array
    }
    public static void main(String[] args) {
        Arraylistclass list = new Arraylistclass();
        list.add(5);
        list.add(10);
        list.add(15);
        System.out.println("Element at index 1: " + list.get(1));
        System.out.println("Size of the list: " + list.size());
        list.remove(1);
        System.out.println("Size after removal: " + list.size());
    }
}


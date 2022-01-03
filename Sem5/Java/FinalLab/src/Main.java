import java.util.AbstractMap;

public class Main {
    public static void main(String[] args) {
        SharedQueue sq = new SharedQueue();
        sq.setLimits("Product 1", new AbstractMap.SimpleImmutableEntry(0, 10));
        sq.setLimits("Product 2", new AbstractMap.SimpleImmutableEntry(0, 10));
        sq.setLimits("Product 3", new AbstractMap.SimpleImmutableEntry(0, 10));
        sq.setLimits("Product 4", new AbstractMap.SimpleImmutableEntry(0, 10));
        Consumer c1 = new Consumer(sq);
        Producer p1 = new Producer(sq);
        Consumer s2 = new Consumer(sq);
    }
}

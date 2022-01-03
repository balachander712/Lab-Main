import java.util.*;
import java.util.concurrent.LinkedBlockingQueue;

public class SharedQueue {
    HashMap<String,Queue<Product>> productQueue;
    protected Map<String, AbstractMap.SimpleImmutableEntry<Integer, Integer>> limit;

    public SharedQueue(HashMap<String, Queue<Product>> productQueue, Map<String, AbstractMap.SimpleImmutableEntry<Integer, Integer>> stockLimits) {
        this.productQueue = productQueue;
        this.limit = stockLimits;
    }

    public SharedQueue(){
        productQueue = new HashMap<>();
        limit = new HashMap<>();
    }

    public synchronized void consume(String productName, int bulkSize){
        if(this.productQueue.get(productName) == null){
            this.productQueue.put(productName, new LinkedBlockingQueue<>());
        }
        Queue productQueue = this.productQueue.get(productName);
        while(productQueue.size() - bulkSize < this.limit.get(productName).getKey()){
            try {
                System.out.println("Waiting to consume");
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        for(int i = 0; i < bulkSize; i++)
            productQueue.remove();
        System.out.println("Consumed " + productName);
        notifyAll();
    }

    public void setLimits(String name,AbstractMap.SimpleImmutableEntry<Integer, Integer> minMaxCount) {
        this.limit.put(name, minMaxCount);
    }

    public synchronized void produce(String productName){
        if(this.productQueue.get(productName) == null){
            this.productQueue.put(productName, new LinkedBlockingQueue<>());
        }
        Queue productQueue = this.productQueue.get(productName);

        while (productQueue.size() == this.limit.get(productName).getValue()) {
            try {
                System.out.println("Waiting to produce");
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        productQueue.add(new Product(productName));
        System.out.println("Produced " + productName);
        notifyAll();
    }

    public HashMap<String, Queue<Product>> getProductQueue() {
        return productQueue;
    }

    public Map<String, AbstractMap.SimpleImmutableEntry<Integer, Integer>> getLimit() {
        return limit;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof SharedQueue)) return false;
        SharedQueue that = (SharedQueue) o;
        return Objects.equals(getProductQueue(), that.getProductQueue()) &&
                Objects.equals(getLimit(), that.getLimit());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getProductQueue(), getLimit());
    }

    @Override
    public String toString() {
        return "SharedQueue{" +
                "productQueue=" + productQueue +
                ", limit=" + limit +
                '}';
    }
}
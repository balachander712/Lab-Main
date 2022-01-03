class Producer implements Runnable {
    SharedQueue productQueue;

    public Producer(SharedQueue productQueue) {
        this.productQueue = productQueue;
        new Thread(this).start();
    }

    @Override
    public void run() {
        productQueue.produce("Product 1");
        System.out.println("Produced Product 1");
        productQueue.produce("Product 2");
        System.out.println("Produced Product 2");
        productQueue.produce("Product 3");
        System.out.println("Produced Product 3");
        productQueue.produce("Product 4");
        System.out.println("Produced Product 4");

    }

}
class Consumer implements Runnable {
    SharedQueue productQueue;

    public Consumer(SharedQueue productQueue) {
        this.productQueue = productQueue;
        new Thread(this).start();
    }

    @Override
    public void run() {
        productQueue.consume("Product 1", 1);
        System.out.println("Consumed Product 1");
        productQueue.consume("Product 2", 1);
        System.out.println("Consumed Product 2");
        productQueue.consume("Product 3", 1);
        System.out.println("Consumed Product 3");
        productQueue.consume("Product 4", 1);
        System.out.println("Consumed Product 4");

    }

}
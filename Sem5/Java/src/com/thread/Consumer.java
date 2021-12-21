package com.thread;

public class Consumer implements Runnable {

    Q q;

    public Consumer(Q q) {
        this.q = q;
        new Thread(this).start();
    }

    @Override
    public void run() {
       while (true){
           q.get();
       }
    }
}

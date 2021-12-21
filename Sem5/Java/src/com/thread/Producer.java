package com.thread;

public class Producer implements Runnable {
    Q q;

    public Producer(Q q) {
        this.q = q;
        new Thread(this).start();
    }


    @Override
    public void run() {
        while (true){
            q.put();
        }
    }
}

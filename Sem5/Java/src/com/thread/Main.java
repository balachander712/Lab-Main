package com.thread;

public class Main {

    public static void main(String[] args) {
        Q q = new Q(true);

        new Producer(q);
        new Consumer(q);
    }
}

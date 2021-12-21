package com.thread;

public class Q {

    boolean isEmpty;
    int n;

    public Q(boolean isValue) {
        n = 0;
        this.isEmpty = isValue;
    }

    public synchronized int put()  {
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        if(!isEmpty){
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        isEmpty = false;
        n++;
        System.out.println("PUT : " + n);
        notify();
        return n;
    }

    public synchronized int get(){
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        if(isEmpty){
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("GOT :" + n);
        isEmpty = true;
        notify();
        return n;
    }
}

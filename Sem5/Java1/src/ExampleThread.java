/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 19pw06
 */
public class ExampleThread implements Runnable {
    
    String string;
    
    public ExampleThread(String string){
        this.string = string;
    }
    
    public void run(){
        for(int i = 0; i < 100; i++){
            System.out.println(string);
        }
    }
    
}

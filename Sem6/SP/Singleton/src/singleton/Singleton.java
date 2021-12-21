/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package singleton;

/**
 *
 * @author 19pw06
 */
public class Singleton {

    /**
     * @param args the command line arguments
     */
    
    private static Singleton obj = new Singleton();
    
    private Singleton(){
        
    }
    
    public static Singleton getInstance(){
        return obj;
    }
    
    public void showMessage(){
        System.out.println("Hello World");
    }
    
    public static void main(String[] args) {
        // TODO code application logic 
        Singleton obj = Singleton.getInstance();
        
        obj.showMessage();
    }
    
}

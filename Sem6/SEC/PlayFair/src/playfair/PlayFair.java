/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package playfair;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

/**
 *
 * @author 19pw06
 */
public class PlayFair {

    /**
     * @param args the command line arguments
     */
    
    String key;
    String plainText;
    char[][] keySquare = new char[5][5];
    
    public PlayFair(String key, String plainText){
        this.key = key.toLowerCase();
        
        this.plainText = plainText.toLowerCase();
        
    }
    
    public void cleanKey(){
        Set<Character> set = new HashSet<>();
        String newKey = "";
        
        for(int i = 0; i < key.length(); i++){
            set.add(key.charAt(i));
        }
        
        Iterator<Character> it = set.iterator();
        
        while(it.hasNext()){
            newKey += (Character) it.next();
        }
        
        this.key = newKey;
    }
    
    
    public void generateKeySquare(){
        HashSet<Character> set = new HashSet<>();
        
        for(int i = 0; i < key.length(); i++){
            if(key.charAt(i) == 'j') continue;
            else set.add(key.charAt(i));
        }
        
        String tempSq = new String(key);
        
        for(int i = 0; i < 26; i++){
            char c = (char)(i + 97);
            if(c == 'j') continue;
            
            if(!set.contains(c)) tempSq += c;
        }
        
        
        for(int i = 0, idx = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                keySquare[i][j] = tempSq.charAt(idx++);
            }
        }
        
        System.out.println("Playfair Cipher Key Matrix:");
        
        for(int i = 0; i < 5; i++){
            System.out.println(Arrays.toString(keySquare[i]));
        }
    }
    
        public String formatPlainText(){
        String message = "";
        
        for(int i = 0; i < plainText.length(); i++){
            if(plainText.charAt(i) == 'j') message += 'i';
            else message += plainText.charAt(i);
        }
        
        for(int i = 0; i < message.length(); i += 2){
            if(message.charAt(i) == message.charAt(i + 1)){
                message = message.substring(0, i + 1) + 'x' + message.substring(i + 1);
            }
        }
        
        if(plainText.length() % 2 == 1) message += 'x';
        
        return message;
        
    }
    
    
    public static void main(String[] args) {
        // TODO code application logic here
        String key = "Problem";
        String plainText = "Heello";
        
        PlayFair pf = new PlayFair(key, plainText);
        pf.cleanKey();
        pf.generateKeySquare();
        System.out.println(pf.formatPlainText());
    }
    

}

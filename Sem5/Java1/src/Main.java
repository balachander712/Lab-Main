/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 19pw06
 */
import java.util.*;

public class Main {
    public static void main(String[] args) {
//        Date dob = new Date(1,1,2021);
//        Date doj = new Date(2,3,2020);
//
//        System.out.println(dob.compareDate(doj));
//
//        Date dummy = new Date(1,1,2021);
//
//        System.out.println(dob.equals(dummy));
//
//        Student student = new Student("Balachander ", "19PW06", dob, doj);
//        System.out.println(student);
//        System.out.println(dob);
        
//          Student[] student = new Student[10];
//          
//          Date date = new Date(1,1,2001);
//          date.setFormat("dd/mm/yy");
//          System.out.println(date);
//          
//          Date date1 = new Date(2,2,2002,"dd/mm/yy");
//          System.out.println(date1);
//          
//          String[] names = new String[] {"Balachander", "Rithesh", "Bharat", "Tarun Pritam", "Ranga", "Seeni",
//                                        "Aravind", "Sheeru", "Mohan", "Neeru"};
//          
//          String[] rollNo = new String[] {"19PW06", "19PW25", "19PW08", "19PW25", "19PW30", "19PW41", "19PW02", 
//                                    "19PW32", "19PW15", "19PW19"};
//          
//          Date[] dob = new Date[] {new Date(1,1,2021), new Date(2,2,2020), new Date(2,2,2020), new Date(2,2,2020),
//                                   new Date(2,2,2020), new Date(2,2,2020), new Date(2,2,2020), new Date(2,2,2020),
//                                   new Date(2,2,2020), new Date(2,2,2020)};
//          
//          Date[] doj = new Date[] {new Date(1,1,2021), new Date(2,2,2020), new Date(2,2,2020), new Date(2,2,2020),
//                                   new Date(2,2,2020), new Date(2,2,2020), new Date(2,2,2020), new Date(2,2,2020),
//                                   new Date(2,2,2020), new Date(2,2,2020)};
//          
////          for(String name : names){
////              System.out.println(name);
////          }
//        
//          for(int i = 0; i < 10; i++){
//              student[i] = new Student(names[i], rollNo[i], dob[i], doj[i]);
//          }
//          
//          for(int i = 0; i < 10; i++){
//              System.out.println(student[i]);
//          }
//        Date dob = new Date(1,1,2021);
//        Date doj = new Date(2,3,2020);
//        
//        Student s1 = new Student("Pro Madman", "19PW06", dob, doj);
//        Student s2 = new Student("Noob Pritam ", "19PW22", dob, doj);
//        Student s3 = new Student("Noob Mechy ", "19PW25", dob, doj);
//            
//        List<Student> list = new ArrayList<>();
//        list.add(s1);
//        list.add(s2);
//        list.add(s3);
//
//        System.out.println(list.contains(new Student("Balachander ", "19PW06", dob, doj)));
//        Collections.sort(list);
//        for(int i = 0; i < list.size(); i++){
//            System.out.println(list.get(i));
//        }


        Thread t1 = new Thread(new ExampleThread("Hello"));
        Thread t2 = new Thread(new ExampleThread("World"));
        
        t1.start();
        t2.start();
                

    }
}

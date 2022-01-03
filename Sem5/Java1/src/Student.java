/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 19pw06
 */
public class Student implements Comparable<Student> {
    private String name;
    private String rollNo;
    private Date dateOfBirth;
    private Date dateOfJoining;

    public Student(String name, String rollNo, Date dateOfBirth, Date dateOfJoining) {
        this.name = name;
        this.rollNo = rollNo;
        this.dateOfBirth = dateOfBirth;
        this.dateOfJoining = dateOfJoining;
    }

    @Override
    public String toString(){
        return new String("Name : " + name + " " + "Roll Number : " + " " + rollNo + " " + "Date of Birth : " + " " + dateOfBirth);
    }

    @Override
    public boolean equals(Object obj){
        if(obj == null) return false;

        if(obj instanceof Student){
            final Student student = (Student) obj;
            if(name.equals(student.name) && rollNo.equals(student.rollNo) && dateOfBirth.equals(student.dateOfBirth) &&
                    dateOfJoining.equals(student.dateOfJoining)){
                return true;
            }
        }

        return false;
    }
    
    public int compareTo(Student st){
        return this.name.compareTo(st.name);
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setRollNo(String rollNo) {
        this.rollNo = rollNo;
    }

    public void setDateOfBirth(Date dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    public void setDateOfJoining(Date dateOfJoining) {
        this.dateOfJoining = dateOfJoining;
    }
    
    
}

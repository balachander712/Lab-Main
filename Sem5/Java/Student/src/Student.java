public class Student {

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



}

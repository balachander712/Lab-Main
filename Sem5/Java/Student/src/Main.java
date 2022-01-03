public class Main {
    public static void main(String[] args) {
        Date dob = new Date(1,1,2021);
        Date doj = new Date(2,3,2020);

        System.out.println(dob.compareDate(doj));

        Date dummy = new Date(1,1,2021);

        System.out.println(dob.equals(dummy));

        Student student = new Student("Balachander ", "19PW06", dob, doj);
        System.out.println(student);
        System.out.println(dob);
    }
}

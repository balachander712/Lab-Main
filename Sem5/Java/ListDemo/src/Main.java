import java.util.Arrays;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        LinkedList<String> list = new LinkedList<>();

        list.add("Java");
        list.add("C++");
        list.add("C");
        list.add(1, "Javascript");
        list.set(1, "Kotlin");

        list.remove(1);

//        for(String lang : list){
//            System.out.println(lang);
//        }

        Object[] o = list.toArray();
        
        System.out.println(Arrays.toString(o));

        //System.out.println(list);
    }
}

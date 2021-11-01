import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        TimeStampList util = new TimeStampList();
        LocalDate date = LocalDate.now();
        LocalTime time = LocalTime.now();
        TimeStamp t1 = new TimeStamp(time, date, new Temperature(true, 51));
        TimeStamp t2 = new TimeStamp(time, date.minusDays(1), new Temperature(true, 52));
        TimeStamp t3 = new TimeStamp(time, date, new Temperature(true, 53));
        TimeStamp t4 = new TimeStamp(time, date.minusDays(2), new Temperature(true, 54));
        TimeStamp t5 = new TimeStamp(time, date, new Temperature(true, 55));

        System.out.println(t1.getDifference(t4));

        List<TimeStamp> list = new ArrayList<>();
        list.add(t1);
        list.add(t2);
        list.add(t3);
        list.add(t4);
        list.add(t5);

        System.out.println(list);
        Collections.sort(list, new DateTimeComparator());
        System.out.println(list);
        Collections.sort(list, new TemperatureComparator());
        System.out.println(list);
        date.minusDays(5);
        double d = util.getAvgTempBetDates(list, date.minusDays(5), date);
        System.out.println(d);

    }
}

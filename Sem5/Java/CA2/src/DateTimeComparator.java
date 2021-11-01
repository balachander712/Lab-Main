import java.util.Comparator;

class DateTimeComparator implements Comparator<TimeStamp> {

    @Override
    public int compare(TimeStamp t1, TimeStamp t2) {
        if (t1.getDate().isEqual(t2.getDate())) {
            if (t1.getTime().isAfter(t2.getTime())) {
                return 1;
            } else if (t1.getTime().isBefore(t2.getTime())) {
                return -1;
            }
            return 0;
        } else if (t1.getDate().isBefore(t2.getDate())) {
            return -1;
        }
        return 1;
    }
}
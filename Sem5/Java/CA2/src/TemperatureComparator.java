import java.util.Comparator;

public class TemperatureComparator implements Comparator {
    @Override
    public int compare(Object o1, Object o2) {
        TimeStamp t1 = (TimeStamp) o1;
        TimeStamp t2 = (TimeStamp) o2;
        return Double.compare(t1.getTemperature().getAsJoule(), t2.getTemperature().getAsJoule());
    }
}
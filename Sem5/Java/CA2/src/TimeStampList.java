import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;

public class TimeStampList {
    public List<TimeStamp> filterByDay (List<TimeStamp> elements, LocalDate date) {
        List<TimeStamp> result = new ArrayList<> ();
        for (TimeStamp item : elements) {
            if (item.getDate().isEqual(date))
                result.add(item);
        }
        return result;
    }

    public double getAvgTemp (List<TimeStamp> elements, LocalDate date) {
        double temperatureSum = 0;
        int counter = 0;
        for (TimeStamp item : elements) {
            if (item.getDate().isEqual(date)) {
                temperatureSum += item.getTemperature().getAsCelsius();
                counter++;
            }
        }
        return temperatureSum/counter;
    }

    public double getAvgTempBetDates (List<TimeStamp> elements, LocalDate startDate, LocalDate endDate) {
        double temperatureSum = 0;
        int counter = 0;
        for (TimeStamp item : elements) {
            if (item.getDate().isAfter(startDate) && item.getDate().isBefore(endDate)) {
                temperatureSum += item.getTemperature().getAsCelsius();
                counter++;
            }
        }
        return temperatureSum/counter;
    }

    public double getAvgTempBetTime (List<TimeStamp> elements, LocalTime startTime, LocalTime endTime) {
        double temperatureSum = 0;
        int counter = 0;
        for (TimeStamp item : elements) {
            if (item.getTime().isAfter(startTime) && item.getTime().isBefore(endTime)) {
                temperatureSum += item.getTemperature().getAsCelsius();
                counter++;
            }
        }
        return temperatureSum/counter;
    }
}

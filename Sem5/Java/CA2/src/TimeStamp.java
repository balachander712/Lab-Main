import java.time.Duration;
import java.util.Objects;
import java.time.LocalDate;
import java.time.LocalTime;


public class TimeStamp {

    private LocalTime time;
    private LocalDate date;
    private Temperature temperature;


    public TimeStamp(LocalTime time, LocalDate date, Temperature temperature) {
        this.time = time;
        this.date = date;
        this.temperature = temperature;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof TimeStamp)) return false;
        TimeStamp timeStamp = (TimeStamp) o;
        return Objects.equals(time, timeStamp.time) &&
                Objects.equals(date, timeStamp.date) &&
                Objects.equals(temperature, timeStamp.temperature);
    }

    @Override
    public int hashCode() {
        return Objects.hash(time, date, temperature);
    }

    @Override
    public String toString() {
        return date.getDayOfMonth() + "/" + date.getMonthValue() + "/" + date.getYear() + ":" + time.getHour() + ":" + time.getMinute() + ":" + time.getSecond() + ":" + temperature;
    }

    public long getDifference(TimeStamp timestamp){
        long timeSeconds =  Duration.between(this.time, timestamp.time).getSeconds();
        long dateSeconds = Duration.between(this.date.atStartOfDay(), timestamp.date.atStartOfDay()).getSeconds();
        return timeSeconds+dateSeconds;
    }

    public LocalTime getTime() {
        return time;
    }

    public void setTime(LocalTime time) {
        this.time = time;
    }

    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    public Temperature getTemperature() {
        return temperature;
    }

    public void setTemperature(Temperature temperature) {
        this.temperature = temperature;
    }
}

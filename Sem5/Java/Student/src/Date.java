import java.time.LocalDate;

public class Date {

    private int day;
    private int month;
    private int year;

    public Date(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public int compareDate(Date date){
        if(day == date.day && month == date.month && year == date.year) return 0;

        if(month == date.month && year == date.year){
            if(day > date.day) return 1;
            else return -1;
        } else if(month == date.month && day == date.day){
            if(year > date.year) return 1;
            else return -1;
        }
        else if(year == date.year && day == date.day){
            if(month > date.month) return 1;
            else return -1;
        } else {
            if(day > date.day) return 1;
            else return -1;
        }
    }

    @Override
    public String toString() {
        return new String(day + "-" + month + "-" + year);
    }

    @Override
    public boolean equals(Object obj){
        if(obj == null) return false;

        if(obj instanceof Date){
            final Date date = (Date) obj;
            if(this.day == date.day && this.month == date.month && this.year == date.year){
                return true;
            }
        }

        return false;
    }

//    public Date addDate(int days){
//        LocalDate date = LocalDate.of(year, month, day).plusDays(days);
//
//        return new Date(date.getDayOfMonth(), date.getMonthValue(), date.getYear());
//
//    }

    public Date addDate(int days){

        int[] monthDay = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int tDay = 1;
        int tMonth = 1;
        int tYear = 2000;

        if(day + days > monthDay[month]){
            if(month + 1 > 12){

            } else {

            }
        } else {

        }

        return new Date(tDay, tMonth, tYear);
    }

    public int getDay() {
        return day;
    }

    public int getMonth() {
        return month;
    }


    public int getYear() {
        return year;
    }
}

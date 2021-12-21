/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 19pw06
 */
public class Date {
    private int day;
    private int month;
    private int year;
    private String format;
    
    public Date(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
        this.format = "dd/mm/yyyy";
    }
    
    public Date(int day, int month, int year, String format) {
        this.day = day;
        this.month = month;
        this.year = year;
        this.format = format;
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
        
        if(format.equals("dd/mm/yyyy"))
            return new String(day + "/" + month + "/" + year);
        if(format.equals("dd/mm/yy")){
            String yr = Integer.toString(year);
            return new String(day + "/" + month + "/" + yr.substring(2));
        }
        if(format.equals("yyyy/mm/dd"))
            return new String(year + "/" + month + "/" + day);
        
        return new String(day + "/" + month + "/" + year);
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

public Date addDaytoDate(int days){
        Date dt = new Date(day, month, year);
        int[] days_in_month = dt.isLeapyear();
        while (true){
            int diff = days - (days_in_month[dt.month - 1] - dt.day);
            if(diff > 0 ){
                days = diff;
                dt.month++;
                dt.day = 0;
                if(dt.month <= 12){
                    continue;
                }
            }else{
                dt.day = dt.day + days;
                break;
            }
            dt.year++;
            dt.month = 1;
            days_in_month = dt.isLeapyear();
        }
        return dt;
    }

    public Date subDayfromDate(int days){
        Date dt = new Date(day, month, year);
        int[] days_in_month = dt.isLeapyear();
        while (true){
            int diff = (days_in_month[dt.month - 1] - dt.day) - days;
            if(diff > 0 ){
                days = diff;
                dt.month--;
                dt.day = days_in_month[dt.month - 1] ;
                if(dt.month >= 0){
                    continue;
                }
            }else{
                dt.day = dt.day - days;
                break;
            }
            dt.year--;
            dt.month = 12;
            days_in_month = dt.isLeapyear();
        }
        return dt;
    }

    private int[] isLeapyear(){
        int[] normalYear = {31,28,31,30,31,30,31,31,30,31,30,31};
        int[] leapYear = {31,29,31,30,31,30,31,31,30,31,30,31};
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)  ){
            return leapYear;
        }
        return normalYear;
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
    
    public void setFormat(String format){
        this.format = format;
    }
}

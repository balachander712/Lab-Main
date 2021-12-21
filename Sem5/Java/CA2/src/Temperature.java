import java.util.Objects;

public class Temperature implements Comparable<Temperature>{

    private boolean isCelsius;
    private double temp;

    public Temperature(boolean isCelsius, double temp) {
        this.isCelsius = isCelsius;
        this.temp = temp;
    }

    public Temperature(Temperature temperature){
        this.isCelsius = temperature.isCelsius();
        this.temp = temperature.getTemp();
    }

    @Override
    public String toString() {
        if(isCelsius) return temp + "C";

        return temp + "J";
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Temperature)) return false;
        Temperature that = (Temperature) o;
        return isCelsius() == that.isCelsius() &&
                Double.compare(that.getTemp(), getTemp()) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(isCelsius(), getTemp());
    }


    public Temperature convert(boolean isCelsius) {
        if (this.isCelsius == isCelsius) return this;
        double newTemp;
        if (this.isCelsius) newTemp = this.temp*1899.1005;
        else newTemp = this.temp/1899.1005;
        return new Temperature(isCelsius, newTemp);
    }

    public double getAsJoule() {
        if (!isCelsius) return temp;
        return temp*1899.1005;
    }

    public double getAsCelsius() {
        if (isCelsius) return temp;
        return temp/1899.1005;
    }

    public boolean isCelsius() {
        return isCelsius;
    }

    public void setCelsius(boolean celsius) {
        isCelsius = celsius;
    }

    public double getTemp() {
        return temp;
    }

    public void setTemp(double temp) {
        this.temp = temp;
    }

    @Override
    public int compareTo(Temperature temp) {
        return Double.compare(this.getAsJoule(), temp.getAsJoule());
    }
}

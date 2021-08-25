public class ComplexNumber {
    private int real;
    private int imag;

    public ComplexNumber(int real, int imag) {
        this.real = real;
        this.imag = imag;
    }

    public ComplexNumber add(ComplexNumber number){

        return new ComplexNumber(real + number.real, imag + number.imag);
    }

    public ComplexNumber multiply(ComplexNumber number){
        int real = this.real * number.real - imag * number.imag;
        int imag = this.real * number.imag + this.imag * number.real;
        return new ComplexNumber(real, imag);
    }

    public int getReal() {
        return real;
    }

    public void setReal(int real) {
        this.real = real;
    }

    public int getImag() {
        return imag;
    }

    public void setImag(int imag) {
        this.imag = imag;
    }
}

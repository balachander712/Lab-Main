public class Main {
    public static void main(String[] args) {
        ComplexMatrix matrix1 = new ComplexMatrix(3,3);
        ComplexMatrix matrix2 = new ComplexMatrix(3,3);

        //ComplexNumber num1 = new ComplexNumber();

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                matrix1.complexArray[i][j] = new ComplexNumber(i,j);
                matrix2.complexArray[i][j] = new ComplexNumber(i,j);
            }
        }

        ComplexMatrix matrix3 = matrix1.addMatrix(matrix2);
        ComplexMatrix matrix4 = matrix1.subtractMatrix(matrix2);
        ComplexMatrix matrix5 = matrix1.multiplyMatrix(matrix2);
        matrix3.printMatrix();
        System.out.println("");
        matrix4.printMatrix();
        System.out.println("");
        matrix5.printMatrix();
    }
}

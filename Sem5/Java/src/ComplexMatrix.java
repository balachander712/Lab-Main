public class ComplexMatrix {

    public ComplexNumber[][] complexArray;
    public int row;
    public int col;


    public ComplexMatrix(ComplexNumber[][] complexArray, int row, int col) {
        this.complexArray = complexArray;
        this.row = row;
        this.col = col;
    }

    public ComplexMatrix(int row, int col) {
        complexArray = new ComplexNumber[row][col];
        this.row = row;
        this.col = col;
    }

    public ComplexNumber[][] getComplexArray() {
        return complexArray;
    }

    public void setComplexArray(ComplexNumber[][] complexArray) {
        this.complexArray = complexArray;
    }

    public int getRow() {
        return row;
    }

    public void setRow(int row) {
        this.row = row;
    }

    public int getCol() {
        return col;
    }

    public void setCol(int col) {
        this.col = col;
    }

    public ComplexMatrix addMatrix(ComplexMatrix matrix){
        ComplexMatrix result = new ComplexMatrix(this.row, this.col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int tempReal = this.complexArray[i][j].getReal() + matrix.complexArray[i][j].getReal();
                int tempImag = this.complexArray[i][j].getImag() + matrix.complexArray[i][j].getImag();
                result.complexArray[i][j] = new ComplexNumber(tempReal, tempImag);
            }
        }

        return result;
    }

    public ComplexMatrix subtractMatrix(ComplexMatrix matrix){
        ComplexMatrix result = new ComplexMatrix(this.row, this.col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int tempReal = this.complexArray[i][j].getReal() - matrix.complexArray[i][j].getReal();
                int tempImag = this.complexArray[i][j].getImag() - matrix.complexArray[i][j].getImag();
                result.complexArray[i][j] = new ComplexNumber(tempReal, tempImag);
            }
        }

        return result;
    }

    public ComplexMatrix multiplyMatrix(ComplexMatrix matrix){
        if (col == matrix.getRow()) {
            ComplexMatrix result = new ComplexMatrix(row, matrix.col);
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < matrix.col; j++) {
                    result.complexArray[i][j] = new ComplexNumber(0,0);
                    for (int k = 0; k < col; k++) {
                        //
                        result.complexArray[i][j]  = result.complexArray[i][j].add(this.complexArray[i][k].multiply(matrix.complexArray[k][j]));
                    }
                }
            }
            return result;
        }
        return null;
    }

    public void printMatrix(){
        for (int i = 0; i < this.row; i++){
            System.out.println();
            for(int j = 0; j < this.col; j++){
                System.out.print(this.complexArray[i][j].getReal() + " + i" + this.complexArray[i][j].getImag());
                System.out.print("\t");
            }
        }
    }
}

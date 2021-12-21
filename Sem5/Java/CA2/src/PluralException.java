import java.util.Objects;

public class PluralException extends Exception {
    private String word;

    public PluralException(String str){
        word = str;
    }

    public String toString()
    {
        return "The word " + word + " is ending with 'S' or 's' ";
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof PluralException)) return false;
        PluralException that = (PluralException) o;
        return Objects.equals(word, that.word);
    }

    @Override
    public int hashCode() {
        return Objects.hash(word);
    }

    public String getWord() {
        return word;
    }

    public void setWord(String word) {
        this.word = word;
    }


}

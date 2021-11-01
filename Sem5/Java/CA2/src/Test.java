public class Test {

    public static void test(String word) throws PluralException{
        int n = word.length();
        if(word.charAt(word.length() - 1) == 'S' || word.charAt(word.length() - 1) == 's'){
            throw new PluralException(word);
        } else {
            System.out.println(word);
        }
    }

    public static void main(String[] args) {
        try{
            test("strings");
        } catch (PluralException e) {
            e.printStackTrace();
        }
    }
}

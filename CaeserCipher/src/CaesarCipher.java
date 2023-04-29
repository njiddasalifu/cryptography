import java.util.Scanner;

public class CaesarCipher {
    static  String alphabet = "abcdefghijklmnopqrstuvwxyz";
    public static String encoding(String pText, int Key){
        // this is the encoding method
        pText = pText.toLowerCase();
        String cText = "";
        for (int i=0; i<pText.length();i++){
            int characterIndex = alphabet.indexOf(pText.charAt(i));
            int newIndex = (characterIndex + Key) % 26;
            //generating the cipher
            char cipherChar = alphabet.charAt(newIndex);
            cText = cText + cipherChar;
        }

        return  cText; // returning the cipher text
    }

    public  static  String decoding(String cText, int Key){
        // this is the decoding method
        cText = cText.toLowerCase();
        String pText = "";
        for (int i=0; i<cText.length();i++){
            int charIndex = alphabet.indexOf(cText.charAt(i));
            int newIndex = (charIndex - Key) % 26;
            if (newIndex < 0){
                newIndex = alphabet.length() + newIndex;
            }
            char plainChar = alphabet.charAt(newIndex);
            pText = pText + plainChar;
        }

        return  pText; // retruning the plaintext
    }

    public  static void  main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter plain Text >> ");
        String plain = scan.nextLine();
        System.out.println("Enter Key >>");
        int Key = scan.nextInt();

        // caling the encoding method
        String cipherText = encoding(plain, Key);

        System.out.println("The cipher text is: " +cipherText);

        // calling the decoding method.
        System.out.println("The decoded message is: " +decoding(cipherText, Key));
    }
}

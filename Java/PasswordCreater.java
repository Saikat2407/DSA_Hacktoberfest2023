// I am trying to create 8 letter password using (a to z) & (A to Z) and (0-9) number 
// first it will shuffle all the letters available and then select 8 first letter from it
package Project;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Password_Managers {
    public static void main(String[] args) {
        // a list named letters created which store all the available letters to create password
        ArrayList<Character> letters = new ArrayList<>();
        for (char ch = 'a'; ch <= 'z'; ch++) {
            letters.add(ch);
        }
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            letters.add(ch);
        }
        for (char nm = '0'; nm < '9'; nm++) {
            letters.add(nm);
        }

        //use to shuffle letters so that password can be created
        Collections.shuffle(letters);
        //      took a sublist
        StringBuilder password = new StringBuilder();
        List<Character> nw = letters.subList(0, 8);
        for (Character character : nw) {
            password.append(character);
        }

        System.out.println("your generated password is:" + password);
    }
}

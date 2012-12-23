package WordsTierTree;

import java.util.ArrayList;
import java.util.Map;
import java.util.TreeMap;
import java.util.regex.Matcher;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class WordTree {

    private static final Pattern russianWord = Pattern.compile("[А-Яа-яA-Za-z0-9-]+"); //[\p{IsCyrillic}]

    private final Map tree = new TreeMap<Character, Object>();

    private ArrayList<String> lemmas = new ArrayList<String>();

    public void addWordForm(String wordForm, String lemma) {

        if (!(is_valid(wordForm) && is_valid(lemma)))
            return;

        Map<Character, Object> node = tree;
        for (int index=0; index < wordForm.length(); index++) {

            Map<Character, Object> next_node = (Map)node.get(wordForm.charAt(index));
            if (next_node != null) {
                node = next_node;
            }
            else {
                TreeMap<Character, Object> map = new TreeMap<Character, Object>();
                node.put(wordForm.charAt(index) ,map);
                node = map;
            }

        }

        int lemmaIndex = getLemmaIndex(lemma);

        // Check is there any lemma for this path and add it if it doesn't exist

        ArrayList<String> word_lemmas = (ArrayList<String> )node.get('#');

        if (word_lemmas == null) {
            word_lemmas = new ArrayList<String>();
            node.put('#', word_lemmas);
        }

        // Check is lemma in list

        int index = word_lemmas.indexOf(lemma);
        if (index < 0)
            word_lemmas.add(lemma);

        System.out.print("Learning WordForm: " + wordForm + "\n");
//        if (word_lemmas.size() > 1) {
//            System.out.print("Mutilemma word: " + wordForm + "\n");
//        }

    }

    private int getLemmaIndex(String lemma) {

        int lemmaIndex = lemmas.indexOf(lemma);

        if (lemmaIndex < 0)  {
            lemmas.add(lemma);
            lemmaIndex = getLemmaIndex(lemma); // to make it fast we can optimize search from O(n) to O(log(N))
        }
        return lemmaIndex;
    }

    private boolean is_valid(String line) {
        if (line == null || line.length() < 1)
            return false;
        // Russian symbols сan be verified here

        //Matcher m = russianWord.matcher(line).matches();

        return russianWord.matcher(line).matches();
    }

    public ArrayList<String> getLemmas(String word) {

        Map<Character, Object> node = tree;

        for (int index=0; index < word.length(); index++) {

            Map<Character, Object> next_node = (Map)node.get(word.charAt(index));
            if (next_node != null) {
                node = next_node;
            }
            else {
                return null;
            }
        }

        ArrayList<String> word_lemmas = (ArrayList<String>)node.get('#');

        return word_lemmas;
    }
}

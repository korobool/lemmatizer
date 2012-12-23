import WordsTierTree.TrainDataParser;
import WordsTierTree.WordTree;

import java.io.IOException;
import java.util.ArrayList;

public class Main {

    private static String line;

    public static void main(String[] args) {

        if (args.length != 1) {
            System.out.print("Train data file is not specified.");
            System.exit(0);
        }
        WordTree words = new WordTree();

        new TrainDataParser().LoadData(args[0], words);

        while (true) {
            System.out.print("input word form >>>");
            String word = getLine();
            //System.out.print(words.getLemmas(word) + "\n");

            ArrayList<String> lemmas = words.getLemmas(word);

            if (lemmas != null) {
                System.out.print(lemmas);
//                for (String lemma : lemmas) {
//                    System.out.print(lemma + "||");
//                }
            }
            System.out.print("\n");
        }
    }

    public static String getLine() {
        java.io.BufferedReader stdin = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        String line = null;
        try {
            line = stdin.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return line;
    }
}

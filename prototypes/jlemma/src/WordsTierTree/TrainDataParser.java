package WordsTierTree;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class TrainDataParser {
    private WordTree words;

    public void LoadData(String dataFile, WordTree words) {
        // Open input file with train data
        this.words = words;
        try {
            BufferedReader br = new BufferedReader(new FileReader(dataFile));
            String line;
            while ((line = br.readLine()) != null) {
                // process the line.
                // System.out.print("Train entry processing: " + line + "\n");
                processLine(line);
            }
            br.close();
        }
        catch (IOException e)
        {
              System.err.print("Couldn't open file.");
        }
    }

    private void processLine(String line) {
        String[] items = line.toLowerCase().replace('ё','е').trim().split(",");

        if (items.length != 2) {
            return;
        }
        String wordForm = items[0];
        String lemma = items[1];

        words.addWordForm(wordForm, lemma);
    }
}

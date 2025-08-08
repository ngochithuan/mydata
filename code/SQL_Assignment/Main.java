import java.io.FileReader;
import java.io.BufferedReader;
import java.util.ArrayList;

public class Main {

    // Read input file
    public static ArrayList<String> readFile(String fileName) {
        ArrayList<String> lines = new ArrayList<>();

        try {
            FileReader fr = new FileReader(fileName);
            BufferedReader br = new BufferedReader(fr);

            String str = br.readLine();
            lines.add(str);

            if (str != null) {
                str = br.readLine();
                lines.add(str);
            }

            br.close();
            fr.close();
        } catch (Exception e) {
            System.out.println("Error!");
        }
        return lines;
    }

    // ArrayList<String>
    public static int convert(ArrayList<String> data) {
        ArrayList<String> lines = new ArrayList<>();
        String str = "";
        String relationShip, entity1, entity2;
        String entities = "";
        int tempIndex = 0;
        for (int i = 0; i < data.size(); i++) {
            str = data.get(i);
            if (str != null) {
                tempIndex = str.lastIndexOf(":");
                relationShip = str.substring(tempIndex + 2);
                entities = str.substring(0, tempIndex);
            }
        }
        System.out.println(entities);
        return tempIndex;
    }

    // Write to ouput file
    public static void writeFile(String filename) {

    }

    public static void main(String[] args) {
        String inputFile = "input1.txt";

        ArrayList<String> data = readFile(inputFile);
        for (int i = 0; i < data.size(); i++) {
            if (data.get(i) == null) {
                continue;
            }
            System.out.println(data.get(i));
        }

        System.out.println(convert(data));
    }
}
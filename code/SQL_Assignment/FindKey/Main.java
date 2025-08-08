import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

public class Main {
    public static ArrayList<String> readFile(String fileName) {
        ArrayList<String> dbSchemas = new ArrayList<>();
        try {
            FileReader fr = new FileReader(fileName);
            BufferedReader br = new BufferedReader(fr);
            String str = br.readLine();
            dbSchemas.add(str);

            if (str != null) {
                str = br.readLine();
                dbSchemas.add(str);
            }

            br.close();
            fr.close();
        } catch (Exception e) {
            System.out.println("Error!");
        }

        return dbSchemas;
    }

    public static ArrayList<DatabaseSchema> convert(ArrayList<String> lines) {
        ArrayList<DatabaseSchema> dbSchemas = new ArrayList<>();
        for (int i = 0; i < dbSchemas.size(); i++) {
            System.out.println(lines.get(i));
        }
        return dbSchemas;
    }

    public static void main(String[] args) {
        System.out.println();
        convert(readFile("input2.txt"));
    }
}
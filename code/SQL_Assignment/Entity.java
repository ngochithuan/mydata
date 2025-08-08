import java.util.ArrayList;

public class Entity {
    public String name;
    public ArrayList<String> attribute;
    public ArrayList<String> primaryKey;
    public ArrayList<String> foreignKey;

    public Entity() {

    }

    public Entity(String name, ArrayList<String> attribute, ArrayList<String> primaryKey,
            ArrayList<String> foreignKey) {
        this.name = name;
        this.attribute = attribute;
        this.primaryKey = primaryKey;
        this.foreignKey = foreignKey;
    }

    public String toString() {
        return "[" + this.name + "]" + " " + "(" + (attribute.toString()) + ")";
    }
}

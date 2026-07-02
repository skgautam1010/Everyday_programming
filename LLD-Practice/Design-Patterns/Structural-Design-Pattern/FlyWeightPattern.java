import java.util.HashMap;
import java.util.Map;

class TreeType {
    private String name;
    private String color;
    private String texture;

    public TreeType(String name, String color, String texture) {
        this.name = name;
        this.color = color;
        this.texture = texture;
    }

    public void draw(int x, int y) {
        System.out.println("Drawing tree at coordinates: " + x +" " + y + " with feature : " + texture + " and color: " + color + " name: " + name);
    }
}


class Tree {
    private int x;
    private int y;
    private TreeType treeType;

    public Tree(int x, int y, TreeType treeType) {
        this.x = x;
        this.y = y;
        this.treeType = treeType;
    }

    public void draw() {
       treeType.draw(x, y);
    }
}

class Factory {
    private static Map<String, TreeType> treeTypeMap = new HashMap<>();

    public static TreeType getTreeType(String name, String color, String texture) {
        String key = name + "-" + color + "-" + texture;

        if(!treeTypeMap.containsKey(key)) {
            TreeType treeType = new TreeType(name, color, texture);
            treeTypeMap.put(key, treeType);
        }
        return treeTypeMap.get(key);
    }
    
}

class Forest {
    public void plantTree(int x, int y, String name, String color, String texture) {
        TreeType treeType = Factory.getTreeType(name, color, texture);
        Tree tree = new Tree(x, y, treeType);
        tree.draw();
    }
}



public class FlyWeightPattern {
    public static void main(String[] args) {
        Forest forest = new Forest();

        for(int i=0;i<10;i++) {
            forest.plantTree(i, i, "Oak", "Green", "Rough");
        }
    }
}

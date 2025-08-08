public class Exercise1
{
    public class Point
    {
        private float x;
        private float y;
        public point2D(float x, float y)
    {
        this.x = x;
        this.y = y;
    }
    public float getX()
    {
        return x;
    }
    public float getY()
    {
        return y;
    }
    public static void main(String[] args) {
        Point point = new Point.point2D(0.0, 0.0);
        System.out.println("point2D: " + point.getX() + point.getY());
    }
    }
    
    
}
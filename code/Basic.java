import java.util.Arrays;

public class Basic
{
	public static int median(int[] a)
	{
		Arrays.sort(a);
		int med = a[(a.length/2)];
		return med;
	}

	public static void main(String[] args)
	{
		int[] a = {9, 3, 2, 4, 5, 9, 3, 1};
		System.out.println(median(a));
	}
}
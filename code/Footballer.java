public class Footballer
{
	private String id;
	private String name;
	private String birthday;
	public Footballer(String id, String name, String birthday)
	{
		this.id = id;
		this.name = name;
		this.birthday = birthday;
	}
	public String getLastName()
	{
		String arr[] = name.split(" ");
		return arr[arr.length - 1 ];
	}	
	
	public String getBirthday()
	{
		return birthday;
	}

	public String getGender()
	{
		int sum = 0;
		for(int i = 0; i < id.length(); i++)
		{
			if(Character.isDigit(id.charAt(i)))
			{
				sum += Integer.parseInt(String.valueOf(id.charAt(i)));
			}
		}
		if (sum%2!=0)
		{return "Male";} 
		else
		{return "Female";}
	}
	
	public static void main (String args[])
	{
		Footballer player = new Footballer("123412","sd","23/12/2008");
		System.out.println("lastname: "+ player.getLastName());
		System.out.println("Gender: " + player.getGender());
		System.out.println("Birthday: " + player.getBirthday());
	}
}
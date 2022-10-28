import java.util.ArrayList;
import java.util.List;
class partitioning
{
	public static void main(String [] args)
	{
		String s = "aab";
		System.out.println(partition(s));
	}
	public static List<List<String>> partition(String s)
	{
		if(s.length()==0)
		{
			return new ArrayList<>();
		}
		List<List<String>> list = new ArrayList<>();
		traverse(list,new ArrayList<>(),s);
		return list;
	}
	public static void traverse(List<List<String>> list, List<String> temp, String s)
	{
		if(s.length()==0)
		{
			list.add(new ArrayList<>(temp));
			return;
		}
		for(int i=0; i<s.length(); i++)
		{
			if(isPalindrome(s.substring(0,i+1)))
			{
				temp.add(s.substring(0,i+1));
				traverse(list,temp,s.substring(i+1));
				temp.remove(temp.size()-1);
			}
		}
	}
	public static boolean isPalindrome(String s)
	{
		int i=0;
		int j=s.length()-1;
		while(i<=j)
		{
			if(s.charAt(i)!=s.charAt(j))
			{
				return false;
			}
			else
			{
				i++;
				j--;
			}
		}
		return true;
	}
}
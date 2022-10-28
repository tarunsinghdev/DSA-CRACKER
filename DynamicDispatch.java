class Parent
{
	void disp()
	{
		System.out.println("I am disp method from Parent's class");
	}
}
class Ankit extends Parent
{
	void disp()
	{
		System.out.println("I am disp method from Ankit's class");
	}
}
class Gautam extends Parent
{
	void disp()
	{
		System.out.println("I am disp method from gautam's class");
	}
}
class Dynamic
{
	public static void main(String [] args)
	{
		Parent p = new Parent();
		Ankit a = new Ankit();
		Gautam g = new Gautam();
		Parent ref;
		ref = a;
		ref.disp();
		ref =g;
		ref.disp();
	}
}
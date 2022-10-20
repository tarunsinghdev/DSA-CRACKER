#include <iostream>
using namespace std;

int dictionaryContains(string &word)
{
	string dictionary[] = {"mobile","samsung","sam","sung",
							"man","mango", "icecream","and",
							"go","i","love","ice","cream"};
	int n = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < n; i++)
		if (dictionary[i].compare(word) == 0)
			return true;
	return false;
}

void wordBreakUtil(string str, int size, string result);

void wordBreak(string str)
{
	wordBreakUtil(str, str.size(), "");
}

void wordBreakUtil(string str, int n, string result)
{
	for (int i=1; i<=n; i++)
	{
		string prefix = str.substr(0, i);

		if (dictionaryContains(prefix))
		{
			if (i == n)
			{
				result += prefix;
				cout << result << endl;
				return;
			}
			wordBreakUtil(str.substr(i, n-i), n-i,
								result + prefix + " ");
		}
	}	
}

int main()
{

	cout << "First Test:\n";
	wordBreak("iloveicecreamandmango");

	cout << "\nSecond Test:\n";
	wordBreak("ilovesamsungmobile");
	return 0;
}

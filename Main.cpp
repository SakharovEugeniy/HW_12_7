#include <iostream>
#include <string>


//Реализован так же функционал для K=0, условно считал этот сценарий как поиск в строке отсутствия кратности любой длинны 


bool HaveSubsring(const std::string& sometext, int argument_for_prefix)
{
	std::string tmp_text = sometext.substr(0, argument_for_prefix);
	for (int i = argument_for_prefix; i < static_cast<int>(sometext.length()); i += argument_for_prefix)
	{
		for (int j = 0; j < argument_for_prefix; j++)
		{
			if (sometext[j + i] != tmp_text[j])
			{
				return false;
			}
		}
	}
	return true;
}

bool IsKPeriodic(const std::string text,int k)
{
	
	int length_text = static_cast<int>(text.length());

	if (length_text == 0)
	{
		return false;
	}

	if (k < 0)
	{
		std::cout << "Wrong K argument";
		return false;
	}

	if (k > length_text)
	{
		return false;
	}

	if (k == 0)
	{
		if (length_text == 1)
		{
			return true;
		}

			
		for (int prefix_length = 1; prefix_length <= length_text / 2; prefix_length++)
		{
			if (length_text % prefix_length != 0)
			{
				return true;
			}


			if (HaveSubsring(text, prefix_length))
			{
				return false;
			}
		}
	}

	if (k <= length_text)
	{
		if (length_text % k != 0)
		{
			return false;
		}

		return HaveSubsring(text, k);
	}
}


int main()
{
	std::string qwer{ "abcabcabc" };
	int k = 3;
	bool param = IsKPeriodic(qwer, k);

	if (param && k!=0)
	{
		std::cout << "The string " << qwer << " is a multiple of " << k << std::endl; ;
	}
	else if (param && k == 0)
	{
		std::cout << "The string is NOT a multiple" << std::endl; ;

	}
	else if (!param && k == 0)
	{
		std::cout << "The string have multiple" << std::endl; ;

	}
	else
	{
		std::cout << "The string " << qwer << " is NOT a multiple of " << k << std::endl; ;
	}

	return 0;
}
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>


std::pair<std::string, int> encode(const std::string& s) {
	int step = 1;
	std::string tempstring = s;
	std::vector<std::string> stringvector;
	for (int i = 0; i < s.length(); ++i)
	{
		for (int j = 0; j < s.length(); ++j)
		{
			tempstring[j] = s[(j + step) % s.length()];
		}
		step++;
		stringvector.push_back(tempstring);
	}
	sort(stringvector.begin(), stringvector.end());
	int i;
	for (i = 0; i < stringvector.size(); ++i)
	{
		if (stringvector[i] == s)
			break;
	}

	for (int j = 0; j < stringvector.size(); ++j)
	{
		tempstring[j] = stringvector[j][s.length() - 1];
	}

	return { tempstring, i };
}

int whatposition(char ch, std::string s, int index)
{
	int count = 0;
	for (int i = 0; i <= index; i++)
	{
		if (ch == s[i]) count++;
		if ((count > 0) && (s[i] != ch)) break;
	}
	return count;
}


int index_pos(int index, std::string s, char ch)
{
	int pos = 0;
	for (pos = 0; index > 0; ++pos)
	{
		if (s[pos] == ch)
			index--;
	}
	return pos - 1;
}


std::string decode(const std::string& s, int n) {
	std::string sorted = s;
	sort(sorted.begin(), sorted.end());
	std::string returned;
	int index = n;
	int tmp = index;
	for (int i = 0; i < s.size(); i++)
	{
		returned += (sorted[index]);
		index = index_pos(whatposition(sorted[index], sorted, index), s, sorted[index]);
	}
	return returned;
}

int main()
{
	std::cout << "Burrows-Wheeler transform" << std::endl << "=========================";
	std::cout << std::endl << "What you want to do?";
	std::cout << std::endl << "e - encode";
	std::cout << std::endl << "d - decode" << std::endl;
	char choice;
	std::string input;
	std::cin >> choice;
	int numb;
	std::pair<std::string, int> tmp;
	switch (choice)
	{
	case'e':
		std::cout << std::endl << "Enter the srting for encode: ";
		std::cin >> input;
		tmp = encode(input);
		std::cout << std::endl << "the output is: " << tmp.first << " The output 'number' is: " << tmp.second;
		break;
	case 'd':
		std::cout << std::endl << "Enter the string for decode: ";
		std::cin >> input;
		std::cout << std::endl << "Enter the 'number' for decode: ";
		std::cin >> numb;
		std::cout << std::endl << "the output is: " << decode(input, numb);
		break;
	default:
		break;
	}


}
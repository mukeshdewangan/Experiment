#include <stack>

#define my_swap(x,y)  int t;t=x;x=y;y=t; 
#include <iostream>
#include <string>
#include <vector>
const bool matchParenthesis(const std::string & sentence)
{
	std::stack<char> parenthesisStack;
	
	//std::vector <std::pair<char, char> > parenthesisPair;
	std::pair<char, char> common('(', ')');
	std::pair<char, char> curly('{', '}');
	std::pair<char, char> square('[', ']');
	std::vector <std::pair<char, char>> parenthesisPairList{ common, curly, square };
	
	std::vector <int> intVector { 23, 43, 12 };
	std::vector <std::string> strVector{ "First", "Second", "Third" };

	//parenthesisPair.push_back(common);
	//parenthesisPair.push_back(curly);
	//parenthesisPair.push_back(square);

	for (char i : sentence)
	{
		
		std::cout << i;
		switch (i)
		{
		case '{': 
		case '(': 
		case '[': 
			parenthesisStack.push(i);
			break;
		case '}':
			char top;
			top = parenthesisStack.top();
			if (top == '{')
			{
				parenthesisStack.pop();
			}
			else
			{
				return false;
			}
			break;
		case ']': 
			top = parenthesisStack.top();
			if (top == '[' )
			{
				parenthesisStack.pop();
			}
			else
			{
				return false;
			}
			break;
		case ')': 
			top = parenthesisStack.top();
			if (top == '(')
			{
				parenthesisStack.pop();
			}
			else
			{
				return false;
			}
			break;

		default:
			break;
			//std::cout << "No parenthesis " << std::endl;
		}
	}
	return (parenthesisStack.empty());
}

int main_matchparenthesis(int argc, char* argv[])
{
	std::string sentence;
	std::getline(std::cin, sentence);
	std::cout << " Sentence is " << sentence << std::endl;

	matchParenthesis(sentence);

	return 0;
}
#include <iostream>

// This function removes spaces from character array(string)
void removeSpaces(char *charArray)
{
	size_t len = strlen(charArray);
	size_t currentPtr = 0, filledPtr = 0;
	while (charArray[currentPtr] != '\0')
	{
		if ( charArray[currentPtr] != ' ' )
		{
			
			charArray[filledPtr] = charArray[currentPtr];
			filledPtr++;
			
		}
		currentPtr++;
	}
	charArray[filledPtr] = '\0';


}

int main(int argc, char* argv[])
{
	char sentence[] = " hel lo Worl d ";
	removeSpaces(sentence);
	std::cout << " spaces removed " <<sentence << std::endl;
	return 0;
}
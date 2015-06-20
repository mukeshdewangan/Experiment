#include <iostream>

int *Function = nullptr;
int *Prefix = nullptr;
void PrefixFunction(char Pattern[])
{
	int patternLength = strlen(Pattern);
	Prefix = new int[patternLength];
	int j = 0;

	for (size_t i = 1; i < patternLength; i++)
	{
		if ( j > 0 && Pattern[j+1] != Pattern[i] )
		{
			j = Prefix[j];
		}
		else if (Pattern[j+1] == Pattern[i])
		{
			j = j + 1;
		}
		Prefix[i] = j;
	}
}

void KMPMatcher(char Text[], char Pattern[] )
{
	int n = strlen(Text);
	int m = strlen(Pattern);
	PrefixFunction( Pattern );
	int j = 0;
	for (size_t i = 0; i < n; i++)
	{
		while ( j > 0 && Pattern[j+1] != Text[i])
		{
			j = Prefix[j];
		}
		if (Pattern[j+1] == Pattern[i])
		{
			j = j + 1;
		}
		if (j == m - 1)
		{
			std::cout << " pattern occurs with " << i-m << " shifts" << std::endl;
			j = Prefix[j];
		}
	}

}

void PrefixTable(int Pattern[], int m)
{
	Function = new int[m];
	int i = 1, j = 0;
	Function[0] = 0;
	while (i<m)
	{
		if (Pattern[i] == Pattern[j])
		{
			Function[i] = j + 1;
			i++, j++;
		}
		else if (j > 0)
		{
			j = Function[j - 1];
		}
		else
		{
			Function[i] = 0;
			i++;
		}
	}
}

int KMPPatternMatcher(char Text[], int n, int Pattern[], int m)
{
	int i = 0, j = 0;
	PrefixTable(Pattern, m);
	while ( i < n )
	{
		if ( Text[i] == Pattern[j] )
		{
			if ( j == m - 1 )
			{
				return i - j;
			}
			else
			{
				i++, j++;
			}
		}
		else if ( j > 0 )
		{
			j = Function[j - 1];
		}
		else
		{
			i++;
		}
	}
	return -1;
}

int main_KMP(int argc, char * argv[])
{

	char Text[] = "acavbaaaabcabcdababa";
	int textLength = strlen(Text);

	int Pattern[] = { 'a', 'b', 'a', 'b', 'a' };
	int patternLength = 5;

	int index = KMPPatternMatcher( Text,textLength,Pattern, patternLength );
	std::cout << " found pattern at index " << index << std::endl;

	char charPattern[] = { 'a', 'b', 'a', 'a' };
	char charText[] = "abababaabca";
	KMPMatcher(Text, charPattern);

	delete Prefix;
	delete Function;
	return 0;
}

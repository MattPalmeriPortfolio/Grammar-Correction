#include <iostream>
#include <cctype>
//declare functions
void getSentence(char sentence[], const int size, std::istream& inStream);
//precondition: inStream is an opened input stream, size is equal to the max size - 1 (to account for the null character) of sentence
//postcondition: fills sentence[] with values from the input stream, until either a period is reached or the max size is reached.
void fixSentence(char input[], char output[], const int size);
//precondition: size is equal to the max size - 1 (to account for null character) of input[] and output[]
//postcondition: fixes grammatical mistakes in input[] and stores the fixed sentence in output[]

//main
int main()
{
	using namespace std;
	//initialize variables
	char badSentence[101] = "", newSentence[101] = "BIGDOGSAYSHI";
	const int PROPER_SIZE = 100;
	//greet user and get input
	cout << "Welcome! This magical program will fix basic grammatical mistakes in any sentence you write in.\n"
		<< "Please enter a sentence under 100 characters long, preferably starting with a letter, and end your input with a period.\n";
	getSentence(badSentence, PROPER_SIZE, cin);
	//fix sentence
	fixSentence(badSentence, newSentence, PROPER_SIZE);
	//output
	cout << "Your fixed sentence is:\n" << newSentence << endl;
	return 0;
}

//define functions
void getSentence(char sentence[], const int size, std::istream& inStream)
{
	int counter = 0;
	char next;
	while (counter < size && inStream.get(next) && next != '.')
	{
		sentence[counter] = next;
		counter++;
	}
	if (counter < size)
	{
		sentence[counter] = next;
		sentence[counter + 1] = '\0';
	}
	else //if counter == size
	{
		sentence[counter] = '\0';
	}
	return;
}

void fixSentence(char input[], char output[], const int size)
{
	using namespace std;
	int counter = 1, outputPosition = 1;
	//uppercase first character
	if (isalpha(input[0]))
		toupper(input[0]);
	output[0] = input[0];
	//lowercase rest and fix spaces
	while (counter < size && input[counter] != '.')
	{
		if (isspace(input[counter]))
		{
			if (isspace(input[counter + 1]))
				counter++;
			else //if its just one space
			{
				output[outputPosition] = ' ';
				counter++; outputPosition++;
			}

		}
		else if (isalpha(input[counter]))
		{
			output[outputPosition] = input[counter];
			tolower(output[outputPosition]);
			counter++; outputPosition++;
		}
		else //if is digit
		{
			output[outputPosition] = input[counter];
			counter++; outputPosition++;
		}
	}
	//end cstring
	if (outputPosition < size)
	{
		output[outputPosition] = '.';
		output[outputPosition + 1] = '\0';
	}
	else
		output[outputPosition] = '\0';
	return;
}
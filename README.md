# Grammar-Correction

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	Replace_Separate_Integers_With_X.cpp (program file containing code)

## Introduction
Book practice project from Problem Solving With C++ Chapter 8. Project 1.
A program that corrects grammatical mistakes in a sentence. 
Written using Microsoft Visual Studio. 

## Algorithm

		1. get input of sentence with the following parameters:
			- max 100 characters
				- get() loop should include check to ensure sentence is not over 100 characters
				- array should be size 101, to account for extra null char
			- should start with a letter - but program will not crash if it isn't
				- ask user to start sentence with letter
			- input should not end with newline character, but with a period
				- get() loop should check for period as end state
		2. correct sentence by rebuilding it in a second array with the following parameters:
			- change first letter (if it is a letter) to uppercase
				- check is letter; then toupper
			- change next letters to lowercase
				- check if is letter, then tolower it
			- remove any extra spaces - should be only one space between words in the sentence; also get rid of newlines
				- check if character is space
					- if it is, check if character after is space 
						- if so, do nothing (do not output char to new array)
						- if not, add a space (constant) to the new array
		3. append a null character to the end, to create a proppa c-string
		4. output to user

## Requirements
No requirements or modules needed for running this program. 

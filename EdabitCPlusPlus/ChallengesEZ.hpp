#pragma once
#include <string>
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <regex>


/* Method Name: identicalFilter
	   Purpose: traverse through an array and return values that have identical numbers throughout
	   Accepts: vector<string> arr
	   Returns: vector<string> hold */
std::vector<std::string> identicalFilter(std::vector<std::string> arr) {
	//variables
	std::vector<std::string> hold = {};
	bool isIdent;
	char testCh;
	//loop through vector contents
	for (int i = 0; i < arr.size(); i++) {
		isIdent = true;
		//assign first value in number to test
		testCh = arr[i][0];
		//loop through number values
		for (int j = 0; j < arr[i].size(); j++){
			if (testCh != arr[i][j]){
				isIdent = false;
				break;
			}
		}
		//add to hold if number is identical
		if (isIdent)
			hold.push_back(arr[i]);
	}
	return hold;
}

/* Method Name: stringPartitionN
	   Purpose: divide a string based on N-value
	   Accepts: string s, int n
	   Returns: vector<string>      */
std::vector<std::string> stringPartitionN(std::string s, int n) {
	//variables
	std::vector<std::string> vHold;
	std::string strHold;

	//loop through word
	for (int i = 0; i < s.length(); ++i){
		for (int j = 0; j < n; j++){
			strHold += s[i+j];
		}
		vHold.push_back(strHold);
		strHold = "";
	}
	return vHold;
}


/* Method Name: minMaxLengthAvg
	   Purpose: determines the minimum value, max value, length of array and average value
	   Accepts: vector<float> arr
	   Returns: vector<float> arr*/
std::vector<double> minMaxLengthAvg(std::vector<double> &arr)
{
	//variables
	std::vector<double> vHold = { 0,0,0,0 };
	//min & max
	vHold[0] = *std::min_element(arr.begin(), arr.end());
	vHold[1] = *std::max_element(arr.begin(), arr.end());
	//Accumulate
	vHold[2] = arr.size();
	vHold[3] = std::accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
	return vHold;
}

/* Method Name: getExtension
	   Purpose: get the extension type for the given string in a vector
	   Accepts: vector<string> vec
	   Returns:	vector<strig>		*/
std::vector<std::string> getExtension(std::vector<std::string> &vec)
{
	std::vector<std::string> holdVec;
	std::string holdStr;
	for (int i = vec.size() - 1; i >= 0; i--) {
		for (int j = vec[i].size() - 1; j >= 0; j--){
			if (vec[i][j] == '.') {
				holdStr = vec[i].erase(0, j + 1);
				holdVec.push_back(holdStr);
				break;
			}
		}
	}
	return holdVec;
}

/* Method Name: checkPalindrome
	   Purpose: checks to see if a word is the same forward and backward
	   Accepts: string str
	   Returns:	bool		*/
bool checkPalindrome(std::string str) {
	std::string hold = str;
	std::reverse(str.begin(), str.end());
	if (hold == str)
		return true;
	else
		return false;
}

/* Method Name: printChar
	   Purpose: prints a sequential char 
	   Accepts: int n, char ch
	   Returns:	void		*/
void printChar(int n, char ch){
	for (int i = 0; i < n; ++i)
		 std::cout << ch;
}

/* Method Name: removeVowels
	   Purpose: remove vowels from a string, Y not included
	   Accepts: string str
	   Returns:	string		*/
std::string removeVowels(std::string str) {
	return std::regex_replace(str, std::regex("[aeiouAEIOU]"), std::string(""));
}

/* Method Name: leftShift
	   Purpose: left shift the vector the number of times given
	   Accepts: vector<int> vec, int num 
	   Returns:	vector<int>		*/
std::vector<int> leftShift(std::vector<int> vec, int num){
	for (int i = 0; i < num; i++) {
		int temp = vec[0];
		vec.erase(vec.begin());
		vec.push_back(temp);
	}
	return vec;
}
/* Method Name: rightShift
	   Purpose: right shift the vector the number of times given
	   Accepts: vector<int> vec, int num 
	   Returns:	vector<int>		*/
std::vector<int> rightShift(std::vector<int> vec, int num) {
	for (int i = 0; i < num; i++) {
		int temp = vec[vec.size() -1];
		vec.pop_back();
		vec.insert(vec.begin(), temp);
	}
	return vec;
}

/* Method Name: formatPhoneNumber
	   Purpose: format a vector into a phone number string
	   Accepts: vector<int> vec
	   Returns: string str			*/
std::string formatPhoneNumber(std::vector<int> vec) {
	std::string str;
	str.reserve(16);
	for (auto n : vec)
		str.append(std::to_string(n));
	str.insert(0, "(");
	str.insert(4, ")");
	str.insert(5, " ");
	str.insert(9, "-");
	return str;
}
/* Method Name:
	   Purpose:
	   Accepts:
	   Returns:			*/
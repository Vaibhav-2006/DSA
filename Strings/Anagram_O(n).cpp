// C++ program to check if two strings
// are anagrams of each other
//O(n) approach
// This will only work for strings with lower case letters.
// We can get over this shortcoming by taking size of count array as 128. 
#include <iostream>
#include<cstring>
using namespace std;
 
bool areAnagram(char* str1, char* str2)
{
    // Create a count array and initialize all values as 0
    int count[26] = { 0 };
    int i;
 
    // For each character in input strings, increment count
    // in the corresponding count array
    for (i = 0; str1[i] && str2[i]; i++) {
        count[str1[i]-97]++;
        count[str2[i]-97]--;
    }
 
    // See if there is any non-zero value in count array
    for (i = 0; i < 26; i++)
        if (count[i])
            return false;
    return true;
}
 
// Driver code
int main()
{
    char str1[] = "geeksforgeeks";
    char str2[] = "forgeeksgeeks";
   
    // Function call
    if (strlen(str1)==strlen(str2)&&areAnagram(str1, str2))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each "
                "other";
 
    return 0;
}

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)

{
    int letters = 0;
    int words = 1;
    int sentences = 0;

    int count_letters(string text);
    string text = get_string("Text: ");

    //Identify the entire string length
    for (int i = 0; i < strlen(text); i++)
    {
        //If the integer is any letter on ASCII table
        if (isalpha(text[i]))
        {
            //Add every letter
            //ISSUE I FACED: letters not Letters!
            letters = letters + 1;
        }

        else if (isspace(text[i]))
        {
            words = words + 1;
        }

        // You can use '.' to mark alphabet characters
        //You can use || for "or"
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences = sentences + 1;
        }
    }

    //Calculate L (average amount of Letters per word * 100), but it's a float.
    //You can change the integers via floats, even alphabets, as such
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    //Calculate index
    //Remember it is an integer that they want
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    {
        if (index < 1)
        {
            printf("Before Grade 1\n");
        }
        else if (index > 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", index);
        }
    }
}
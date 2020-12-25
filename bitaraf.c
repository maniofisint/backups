#include <stdio.h>

int first_function(char* word, char* sentence, int word_length, int sentence_length)
{
    int counter = 0;
    for (int i =0 ; i <= sentence_length-word_length; i++){
        int flag = 1;
        for (int j = 0 ; j < word_length ; j++){
            if (word[j] != sentence[i+j]){
                flag = 0;
                break;
            }
            
        }
        if (flag == 1){
            counter++;
        }
    }
    return counter;
    
};



int main()
{
    char word[] = "ali";
    char sentence[] = "ali mohammad ali ali";
    printf("%s", sentence);
    int x = first_function(word, sentence, 3, 20 );
    printf("\n%d",x);
    
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
 return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
   return document[k-1][m-1];
}

char*** kth_paragraph(char**** document, int k) {
 return document[k-1];
}

char**** get_document(char* text) {
    int paragraph_count = 1;
    
    for (int i = 0; text[i] != '\0'; i++) 
    {
        if (text[i] == '\n')
        paragraph_count++;
    }

    char ****pararaph = calloc(paragraph_count, sizeof(char***));

    // loop through paragraphs
    char* ptr = text;
   

    for (int i = 0; i < paragraph_count; i++) {
        int sentence_count = 1;
        char* paragraph_start = ptr; 
        while (*ptr != '\n' && *ptr != '\0') {
            if (*ptr == '.')
                sentence_count++;
            ptr++;
        }
        ptr++; // skip '\n'
        char ***sentence = calloc(sentence_count, sizeof(char**));
        pararaph[i] = sentence;
        
        
          for (int j = 0; j < sentence_count; j++) {      // sentence loop (INSIDE paragraph loop)
        char* sentence_start = paragraph_start;
        
        int word_count = 1;
        char *word_start = sentence_start;
        while (*paragraph_start != '.' && *paragraph_start != '\0') {
            if (*paragraph_start == ' ')
                word_count++;
            paragraph_start++;
        }
        paragraph_start++;
        
        char **words = calloc(word_count, sizeof(char*));
        sentence[j] = words;
        
        for (int k = 0; k < word_count; k++)
        {
        int letter_count = 1;
        char* word_begin = word_start;
        while (*word_start != ' ' && *word_start != '.' && *word_start != '\0') {
            letter_count++;
            word_start++;
        }
        word_start++;
        
        char *letters = calloc(letter_count, sizeof(char));
        words[k] = letters;
        strncpy(letters, word_begin, letter_count - 1);
        letters[letter_count - 1] = '\0';
        }
    
    }
    
    
    }
    return pararaph;
    
}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
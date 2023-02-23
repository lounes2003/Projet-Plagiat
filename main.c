#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

struct _word {
    char *text;
    int count;
    struct _word *next;
};
typedef struct_word word ; 

struct _sentence {
    char *text;
    struct _sentence *next;
}; 
typedef strcut_sentence Sentence;
/*creation de la structure */
Word *init_word(const char *text) {
    Word *word = (Word *)malloc(sizeof(Word));
    word->text = (char *)malloc(sizeof(char) * (strlen(text) + 1));
    strcpy(word->text, text);
    word->count = 1;
    word->next = NULL;
    return word;
}
/*creation de la structure */
Sentence *init_sentence(const char *text) {
    Sentence *sentence = (Sentence *)malloc(sizeof(Sentence));
    sentence->text = (char *)malloc(sizeof(char) * (strlen(text) + 1));
    strcpy(sentence->text, text);
    sentence->next = NULL;
    return sentence;
}
/*Word**list c'est des doubles pointeurs essentiels pour modifier le contenu des listes chainées , current c'est le mot actuel*/
void add_word(Word **list, const char *text) {
    Word *current = *list;
    while (current != NULL) {
        if (strcmp(current->text, text) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    Word *new_word = init_word(text);
    new_word->next = *list;
    *list = new_word;
}
/*ajoute les phrases */
void add_sentence(Sentence **list, const char *text) {
    Sentence *new_sentence = init_sentence(text);
    new_sentence->next = *list;
    *list = new_sentence;
}
/*se debarasse des ponctuations pour ne pas les prendre en compte dans la detection du plagiat */
void remove_punctuation(char *word) {
    int length = strlen(word);
    if (word[length - 1] == '.' || word[length - 1] == ',' || word[length - 1] == ';' || word[length - 1] == ':' || word[length - 1] == '!' || word[length - 1] == '?') {
        word[length - 1] = '\0';
    }
}
/*compare les mots un par un */
int compare_words(const void *a, const void *b) {
    Word word1 = *(Word *)a;
    Word word2 = *(Word *)b;
    return word2->count - word1->count;
}
/*lecture des phrases */
int read_sentence(FILE *file, char *sentence) {
    int c, i = 0;
    while ((c = fgetc(file)) != EOF) {
    if (c == '.') {
        sentence[i++] = (char)c;
        sentence[i] = '\0';
        return 1;
    }
    sentence[i++] = (char)c;
    }
    return 0;
}
/*affiche les mots en commun*/
void print_common_words(Word *list1, Word *list2) {
    int common_word_count = 0;
    Word *common_words = (Word *)malloc(sizeof(Word *) * MAX_WORD_LENGTH);
    Word *current1 = list1;
    while (current1 != NULL) {
    Word *current2 = list2;
    while (current2 != NULL) {
        if (strcmp(current1->text, current2->text) == 0) {
        common_words[common_word_count++] = current1;
        break;
        }
        current2 = current2->next;
    }
    current1 = current1->next;
    }

    qsort(common_words, common_word_count, sizeof(Word *), compare_words);

    printf("Common words:\n");
    for (int i = 0; i < common_word_count; i++) {
    printf("%s: %d\n", common_words[i]->text, common_words[i]->count);
    }
}

/*affiche les phrases similaires aux deux fichiers */
void print_similar_sentences(Sentence *list1, Sentence *list2, int total_sentences_count) {
    Sentence *current1 = list1;
    int common_sentences_count=0;
    while (current1 != NULL) {
    Sentence *current2 = list2;
    while (current2 != NULL) {
        if (strcmp(current1->text, current2->text) == 0) {
        printf("Similar sentence: %s\n", current1->text);
        common_sentences_count++;
        break;
        }
        current2 = current2->next;
    }
    current1 = current1->next;
    }
    printf("Le taux de plagiat du fichier 1 par rapport au fichier 2 est: %d%%",(common_sentences_count/total_sentences_count)*100);
}

int main(int argc, char **argv) {
    if (argc < 3) {
    printf("Usage: plagiarism_detector file1 file2\n");
    return 1;
    }
    FILE *file1 = fopen(argv[1], "r");
    if (file1 == NULL) {
    printf("Could not open file %s\n", argv[1]);
    return 1;
    }

    FILE *file2 = fopen(argv[2], "r");
    if (file2 == NULL) {
    printf("Could not open file %s\n", argv[2]);
    return 1;
    }

    char word[MAX_WORD_LENGTH];
    Word *list1 = NULL;
    int count_words_f1=0;
    while (fscanf(file1, "%s", word) != EOF) {
    remove_punctuation(word);
    add_word(&list1, word);
    count_words_f1++;
    }

    Word *list2 = NULL;
    while (fscanf(file2, "%s", word) != EOF) {
    remove_punctuation(word);
    add_word(&list2, word);
    }

    print_common_words(list1, list2);

    rewind(file1);
    rewind(file2);

    char sentence[MAX_SENTENCE_LENGTH];
    Sentence *sentences1 = NULL;
    int total_sentences_count=0;
    while (read_sentence(file1, sentence)) {
    add_sentence(&sentences1, sentence);
    total_sentences_count++;
    }

    Sentence *sentences2 = NULL;
    while (read_sentence(file2, sentence)) {
    add_sentence(&sentences2, sentence);
    }

    print_similar_sentences(sentences1, sentences2, total_sentences_count);

    fclose(file1);
    fclose(file2);
    return 0;
}

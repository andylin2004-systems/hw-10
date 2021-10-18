#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct pokemon {
    char *name;
    int hp;
    struct pokemon *evolvesTo;
};

void printPokemon(struct pokemon * x){
    printf("This Pokemon is %s, with a max HP of %d\n", x->name, x->hp);
}

struct pokemon * allocPokemon(char *name, int hp){
    struct pokemon *p = malloc(sizeof(struct pokemon));
    p->name = name;
    p->hp = hp;
    return p;
}

char * randomStringGen(char * string, int length){
    int i;
    for (i = 0; i < length - 1; i++){
        string[i] = 'a' + rand() % 26;
    }
    string[length - 1] = '\0';
    return string;
}

void print_list(struct pokemon * p){
    printPokemon(p);
    if (p->evolvesTo){
        print_list(p->evolvesTo);
    }
}

struct pokemon * insert_front(struct pokemon * y, char* name, int hp){
    struct pokemon *new = allocPokemon(name, hp);
    new->evolvesTo = y;
    return new;
}

struct pokemon * free_list(struct pokemon * paulAbandonedMe){
    while (paulAbandonedMe){
        struct pokemon *next = paulAbandonedMe->evolvesTo;
        free(paulAbandonedMe);
        paulAbandonedMe = next;
    }
    return paulAbandonedMe;
}

struct pokemon * remove_node(struct pokemon *front, char* name){
    struct pokemon *prev = front;
    struct pokemon *current = front;
    struct pokemon *next = front->evolvesTo;
    while (current)
    {
        printf("check %s", current->name);
        if (strcmp(current->name, name) == 0)
        {
            prev->evolvesTo = next;
            if (current == front){
                front = current->evolvesTo;
            }
            free(current);
            return front;
        }
        else
        {
            prev = current;
            current = current->evolvesTo;
            next = current->evolvesTo;
        }
    }
    return front;
}

int main(){
    struct pokemon *pikachu = allocPokemon("Pikachu", 40);
    pikachu->evolvesTo = allocPokemon("Raichu", 80);
    struct pokemon *pichu = insert_front(pikachu, "Pichu", 20);
    print_list(pichu);
    free_list(pichu);
    pikachu = allocPokemon("Pikachu", 40);
    pikachu->evolvesTo = allocPokemon("Raichu", 80);
    pichu = insert_front(pikachu, "Pichu", 20);
    remove_node(pichu, "Raichu");
    print_list(pichu);
}
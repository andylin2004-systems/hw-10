#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
    if (paulAbandonedMe->evolvesTo){
        free_list(paulAbandonedMe->evolvesTo);
    }
    free(paulAbandonedMe);
    return paulAbandonedMe;
}

int main(){
    struct pokemon *pikachu = allocPokemon("Pikachu", 40);
    pikachu->evolvesTo = allocPokemon("Raichu", 80);
    struct pokemon *pichu = insert_front(pikachu, "Pichu", 20);
    print_list(pichu);
}
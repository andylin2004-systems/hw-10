struct pokemon {
    char *name;
    int hp;
    struct pokemon *evolvesTo;
};

void printPokemon(struct pokemon * x);
struct pokemon * allocPokemon(char *name, int hp);
char * randomStringGen(char * string, int length);
void print_list(struct pokemon * p);
struct pokemon * insert_front(struct pokemon * y, char* name, int hp);
struct pokemon * free_list(struct pokemon * paulAbandonedMe);
struct pokemon * remove_node(struct pokemon *front, char* name);
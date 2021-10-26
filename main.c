#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "hw-10.h"

int main(){
    struct pokemon *pikachu = allocPokemon("Pikachu", 40);
    pikachu->evolvesTo = allocPokemon("Raichu", 80);
    pikachu = insert_front(pikachu, "pichu", 20);
    print_list(pikachu);
    free_list(pikachu);
    printf("oof\n");
    pikachu = allocPokemon("Pikachu", 40);
    pikachu->evolvesTo = allocPokemon("Raichu", 80);
    pikachu = insert_front(pikachu, "pichu", 20);
    pikachu = remove_node(pikachu, "Raichu");
    print_list(pikachu);
    pikachu = free_list(pikachu);
    // printPokemon(pikachu->evolvesTo);
    print_list(pikachu);
}
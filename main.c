#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "hw-10.h"

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
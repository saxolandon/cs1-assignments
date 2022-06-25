#include <stdio.h>

#define MAX_INGREDIANTS 10000
#define MAX_ITEMS 100
#define MAX_RECIPES 10000
#define MAX_SMOOTHIES 10000

typedef struct item {
    int itemID;
    int numParts;
} item;

typedef struct recipe {
    int numItems;
    item* itemList;
    int totalParts;
} recipe;

char** readIngrediants(int numIngrediants);
recipe* readRecipe(int numItems);
recipe** readAllRecipes(int numRecipies);
double* calculateOrder(int numSmoothies, recipe** recipeList, int numIngrediants);
void printOrder(char** ingrediantNames, double* orderList, int numIngrediants);
void freeIngrediants(char** ingredientList, int numIngrediants);
void freeRecipies(recipe* allRecipes, int numRecipes);

int main(void) {
    printf("Hello, World\n");
    return 0;
}
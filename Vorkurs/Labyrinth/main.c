#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX 255

typedef struct {
	int posX;
	int posY;
}Position;

void printarr(int n, int m, char arr[n][m]) {
	for (int i = 0;i<n;i++) {
		for (int j = 0;j<m;j++) {
			printf("[%c]\t", arr[i][j]);
		}
		printf("\n\n");
	}
}

Position findPositionOf(int sizeX, int sizeY, char arr[sizeX][sizeY], char x) {
	Position point;
	
	for (int i = 0;i<sizeX;i++) {
		for (int j = 0;j<sizeY;j++) {
			if (arr[i][j] == x) {
				point.posX = i;
				point.posY = j;
				return point;					
			}
		}
	}
	
	point.posX = -1;
	point.posY = -1;
	
	return point;
}

void getSurroundings(int sizeX, int sizeY, char arr[sizeX][sizeY], Position *pos, char surroundings[3][3]) {
	for (int i = 0;i<3;i++) {
    	for (int j = 0;j<3;j++) {
    		surroundings[i][j] = arr[i-1+pos->posX][j-1+pos->posY];
    	}
    }
	
}

int findPath(int sizeX, int sizeY, char labyrinth[sizeX][sizeY], 
				Position *start, Position *final, char surroundings[3][3]) {
	Position freespot;
	
	printarr(3, 3, surroundings);
	
	freespot = findPositionOf(3, 3, surroundings, ' ');
	
	if (freespot.posX != -1) {
		surroundings[start->posX][start->posY] = '-';
		findPath(sizeX, sizeY, labyrinth, &freespot, final, surroundings);
	}
   	
    return 0;
}

void loadLab(char *a, int sizeX, int sizeY, char lab[sizeX][sizeY]) {
	FILE *fIn = fopen(a, "r");
    char labyrinth[sizeX][sizeY];
    char buffer[MAX];
    
    for (int i = 0;i<sizeX;i++) {
    	for (int j = 0;j<sizeY;j++) {
    		lab[i][j] = 'X';
    	}
    }
    
    printf("lade Datei in Array\n");
    for(int i = 0; i < sizeX; i++) {
        if(fgets(buffer, MAX, fIn) == NULL)
            printf("Größe des Labyrinths nicht korrekt");
        for(int j = 0; j < sizeY && buffer[j] != '\n'; j++) {
            lab[i][j] = buffer[j];
        }
    }
    fclose(fIn);
}

int solveLabyrith(char *a, int sizeX, int sizeY) {
    char labyrinth[sizeX][sizeY];
    loadLab(a, sizeX, sizeY, labyrinth);
    
    printarr(sizeX, sizeY, labyrinth);
    
    Position start = findPositionOf(sizeX, sizeY, labyrinth, '$');
    Position final = findPositionOf(sizeX, sizeY, labyrinth, '*');
    
	char surroundings[3][3];
    
    getSurroundings(sizeX, sizeY, labyrinth, &start, surroundings);
    
    findPath(sizeX, sizeY, labyrinth, &start, &final, surroundings);
  
    printarr(sizeX, sizeY, labyrinth);
    return 0;
}


int main() {
    solveLabyrith("labyrinth.txt",8,16);
    return 1;
}

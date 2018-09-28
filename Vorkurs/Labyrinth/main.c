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

Position findNextFreePosition(int sizeX, int sizeY, char arr[sizeX][sizeY]) {
	Position point;
	
	if (arr[0][1] == ' ') {
		point.posX = 0;
		point.posY = 1;
		return point;
	}
	if (arr[1][2] == ' ') {
		point.posX = 1;
		point.posY = 2;
		return point;
	}
	if (arr[1][0] == ' ') {
		point.posX = 1;
		point.posY = 0;
		return point;
	}
	if (arr[2][1] == ' ') {
		point.posX = 2;
		point.posY = 1;
		return point;
	}
	
	point.posX = -1;
	point.posY = -1;
	
	return point;
}

void getSurroundings(int sizeX, int sizeY, char arr[sizeX][sizeY], Position *pos, char surroundings[3][3]) {
	for (int i = 0;i<3;i++) {
    	for (int j = 0;j<3;j++) {
    		if (i == 1 && j == 1 && surroundings[1][1] == ' ') { 
    			surroundings[1][1] = '-'; 
	    		continue;
    		}
    		surroundings[i][j] = arr[i-1+pos->posX][j-1+pos->posY];
    	}
    }
	
}

int findPath(int sizeX, int sizeY, char labyrinth[sizeX][sizeY], Position *start, char target) {
	Position freespot;
	Position waypoint;
	char surroundings[3][3];
		
	getSurroundings(sizeX, sizeY, labyrinth, start, surroundings);
	
	if(findPositionOf(3, 3, surroundings, target).posX != -1) return 0;
	
	
	while(freespot.posX != -1) {
		freespot = findNextFreePosition(3, 3 ,surroundings);
		printarr(3, 3, surroundings);
		printf("%i_%i\n", start->posX, start->posY);
		printf("%c\n", surroundings[2][1]);
		
		if (freespot.posX == -1) return 1;
		surroundings[freespot.posX][freespot.posY] = '-';
		waypoint.posX = start->posX+freespot.posX-1;
		waypoint.posY = start->posY+freespot.posY-1;
		if (findPath(sizeX, sizeY, labyrinth, &waypoint, target) == 0) {
			printf("Weg gefunden!");
			labyrinth[freespot.posX][freespot.posY] = '.';
		}
		
	}
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
    
    findPath(sizeX, sizeY, labyrinth, &start, '*');
  
    printarr(sizeX, sizeY, labyrinth);
    return 0;
}


int main() {
    solveLabyrith("labyrinth.txt",8,16);
    return 1;
}

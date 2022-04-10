#include <stdio.h>

char player='x';
int box;
//char plane[11][11];
char small_plane[9]={'#','#','#','#','#','#','#','#','#'};
int rounds;
char plane[11][11]={
{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '},
{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '},
{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '},
{'#','#','#','#','#','#','#','#','#','#','#'},
{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '},
{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '},
{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '},
{'#','#','#','#','#','#','#','#','#','#','#'},
{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '},
{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '},
{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '}};


void drawplane(){
  for (int x = 0; x < 11; x++) {
    for (int y = 0; y < 11; y++) {
      printf("%c",plane[y][x]);
    }
    printf("\n");
  }
}

void boxmade(int x,int y){
  if((rounds%2)==0){
    plane[x][y]='x';
    plane[x][y+2]='x';
    plane[x+1][y+1]='x';
    plane[x+2][y]='x';
    plane[x+2][y+2]='x';
  }
  else{
    plane[x+1][y]='o';
    plane[x][y+1]='o';
    plane[x+2][y+1]='o';
    plane[x+1][y+2]='o';
  }
}

void setbox(int box){
    switch (box) {
      case 1:
      boxmade(0,0);
        small_plane[box-1]=player;
         break;
      case 2:
      boxmade(4,0);
      small_plane[box-1]=player;
       break;
      case 3:
      boxmade(8,0);
        small_plane[box-1]=player;
        break;
      case 4:
      boxmade(0,4);
        small_plane[box-1]=player;
        break;
      case 5:
      boxmade(4,4);
        small_plane[box-1]=player;
        break;
      case 6:
      boxmade(8,4);
        small_plane[box-1]=player;
        break;
      case 7:
      boxmade(0,8);
        small_plane[box-1]=player;
        break;
      case 8:
      boxmade(4,8);
        small_plane[box-1]=player;
        break;
      case 9:
      boxmade(8,8);
        small_plane[box-1]=player;
        break;
    }
}
int main() {
  drawplane();
  for(;;){
    if ( (box = getch())!= EOF)  //yes, getchar() returns int
      {
        if(box-'0'<=9){
          system("cls");
          setbox(box-'0');
          rounds++;
          printf("rounds: %i\n",rounds);
          printf("box: %c\n",box);
          drawplane();
        }
      }
  }
   return 0;
}

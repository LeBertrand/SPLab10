#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Programmer: Stepan Pylypchuk
 * Assigment 10
 * Description: Create the program that reads a file of music album and sorts
 * Then displays them to the user
*/

#define TOTAL_LIMIT 249

typedef struct{
                char song[100];
                char artist[100];
                int time[100];
                } Albums;

void bubble_sort( Albums arr[ ], int n, int s, int a );
int read_album_nextline( char *album_in,  Albums arr[ ] );


int main ( ){

    char str[100];
    char albums_list[249];
    Albums All_songs [ 249 ];
    FILE *album_in;
    read_album_nextline( "album.txt",  All_songs);
    int num_1;
    int num_2;
    printf("Welcome to Casey Kasem Presents: America's Top 10 Through the Years - The 1950sr!\n");
    printf("\nHow do you want to see the data sorted?\n");
    printf("\n[ 1 - by title, 2 - by artist, 3 - by song length, 4 - exit ] ? \n" );
    scanf("%d", &num_1);
        while (num_1 != 4)
        {
                printf( "\n Ascending[1] or descending[2] order? \n" );
                scanf("%d", &num_2);
                bubble_sort( All_songs, 249,  num_1, num_2 );

        }
int i;
for(i=0; i<249; i++)
printf("%s",All_songs[i].song) ;
return EXIT_SUCCESS;
}

int read_album_nextline( char *album_in , Albums albums[]){
        album_in = fopen("album.txt", "r");
        char str[TOTAL_LIMIT];

        if (album_in == NULL)
        {
                puts("No file was not read");
        }
        else{
                puts("A file was read");
                int line_count = 0, song_count = 0;

                while(fgets(str,  TOTAL_LIMIT, album_in) != NULL){
                        str[strlen(str) - 1] = '\0';
                        if(str[0] != '*'){
                                if(line_count %3 == 0) {
                                        strcpy(albums[song_count].song , str);
                                }
                                if(line_count %3 == 1){
                                        strcpy(albums[song_count].arti st, str);
                                }
                                if(line_count %3 == 2){
                                        albums[song_count].time = atoi(str);
                                        song_count++;
                                }

                                line_count++;
                        }
                }
                fclose(album_in);

        }
        return song_count;
}



void bubble_sort( Albums arr[ ] , int n,int s,int a )
{
 int i, j;
 Albums temporary;
    for( i = 0; i < n - 1; i++ )
        for ( j = 0; j < n - i - 1; j++ ){
            if(s==1 && a==1){//sorting by song name asending
                if ( strcmp(arr[ j ].song,  arr[ j + 1 ].song ) > 0 )
                 {
                    temporary = arr[ j ];
                    arr[ j ] = arr[ j + 1 ];
                    arr[ j + 1 ] = temporary;
                }
                else if (s==1&& a==2){
                    if ( strcmp(arr[ j ].song,  arr[ j + 1 ].song ) < 0 )
                    {
                    temporary = arr[ j ];
                    arr[ j ] = arr[ j + 1 ];
                    arr[ j + 1 ] = temporary;
                    }
                }
            }

            else {//sort by artist

        // for( i = 0; i < n - 1; i++ )
        //     for ( j = 0; j < n - i - 1; j++ )
        if(s==2 && a==1){//sorting by artist name asending
                if ( strcmp(arr[ j ].artist,  arr[ j + 1 ].artist ) > 0 )
                 {
                temporary = arr[ j ];
                 arr[ j ] = arr[ j + 1 ];
                 arr[ j + 1 ] = temporary;
                }
        else if (s==1 && a==2){
                if ( strcmp(arr[ j ].artist,  arr[ j + 1 ].artist ) < 0 )
                 {
                temporary = arr[ j ];
                 arr[ j ] = arr[ j + 1 ];
                 arr[ j + 1 ] = temporary;
                }

        }
    }



// else {

// for( i = 0; i < n - 1; i++ )
//         for ( j = 0; j < n - i - 1; j++ )
//         if(s==3&& a==1){//sorting by time name asending
//                 if ( strcmp(arr[ j ].time,  arr[ j + 1 ].time ) > 0 )
//                  {
//                 temporary = arr[ j ];
//                  arr[ j ] = arr[ j + 1 ];
//                  arr[ j + 1 ] = temporary;
//                 }
//         else if (s==3 && a==2){
//                 if ( strcmp(arr[ j ].time,  arr[ j + 1 ].time ) < 0 )
//                  {
//                 temporary = arr[ j ];
//                  arr[ j ] = arr[ j + 1 ];
//                  arr[ j + 1 ] = temporary;
//                 }

//         }


return;
}
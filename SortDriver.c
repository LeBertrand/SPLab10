/*
 * Test Deriver for bubble sort.
 * Programmer: Shmuel Jacobs
 * Date: April 30
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.c"

int
main()
{
	Albums layla, mr_jones, john_henry;

	strcpy(layla.artist, "Eric Clapton");
	strcpy(layla.song, "Layla");
	layla.time = 428;

	strcpy(mr_jones.artist, "Counting Crows");
	strcpy(mr_jones.song, "Mr. Jones");
	mr_jones.time = 272;

	strcpy(john_henry.artist, "Joe Bonamassa");
	strcpy(john_henry.song, "The Ballad of John Henry");
	john_henry.time = 386;

	Albums playlist[] = {john_henry, layla, mr_jones};

	bubble_sort(playlist, 3, 1, 1);
	FILE* output = fopen("sort_driver_output.txt", "w");
	
	fprintf(output, "%s | ", playlist[0].song);
	fprintf(output, "%s | ", playlist[1].song);
	fprintf(output, "%s | \n", playlist[2].song);
	
	//Albums playlist[] = {john_henry, layla, mr_jones};

	bubble_sort(playlist, 3, 1, 2);
	//FILE* output = fopen("sort_driver_output.txt", "w");

	fprintf(output, "\n%s | ", playlist[0].song);
	fprintf(output, "%s | ", playlist[1].song);
	fprintf(output, "%s | \n", playlist[2].song);

	// fputs(output, "\nNow sort by artist.\n");
	
	bubble_sort(playlist, 3, 2, 1);
	
	fprintf(output, "%s | ", playlist[0].artist);
	fprintf(output, "%s | ", playlist[1].artist);
	fprintf(output, "%s | \n", playlist[2].artist);
	
	// selection_sort_time_ascending(playlist, 3);
	
	// fprintf(output, "%d | ", playlist[0].time);
	// fprintf(output, "%d | ", playlist[1].time);
	// fprintf(output, "%d | \n", playlist[2].time);
	
	fclose(output);
}

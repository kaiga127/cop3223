#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

int main(int argc, char *argv[]) {
    Playlist pl;
    char line[300];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    playlist_init(&pl);

    playlist_load(&pl, argv[1]);

    while (1) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "p") == 0) {
            playlist_print(&pl);
        } else if (strcmp(line, "r") == 0) {
            playlist_print_reverse(&pl);
        } else if (strcmp(line, "t") == 0) {
            int total = playlist_total_duration(&pl);
            int hour = total / 3600;
            int minute = (total % 3600) / 60;
            int second = total % 60;

            printf("Total: ");

            if (hour > 0) {
                printf("%d:%d:%d\n", hour, minute, second);
            } else {
                printf("%d:%d\n", minute, second);
            }
        } else if (strncmp(line, "a ", 2) == 0) {
            char data[300];
            char *first_b;
            char *second_b;
            char *title;
            char *artist;
            int duration;

            strcpy(data, line + 2);

            first_b = strchr(data, '|');

            if (first_b != NULL) {
                second_b = strchr(first_b + 1, '|');
                if (second_b != NULL) {
                    *first_b = '\0';
                    *second_b = '\0';
                    title = data;
                    artist = first_b + 1;
                    duration = atoi(second_b + 1);

                    playlist_append(&pl, title, artist, duration);
                }
            }
        } else if (strncmp(line, "pre ", 4) == 0) {
            char data[300];
            char *first_b;
            char *second_b;

            strcpy(data, line + 4);

            first_b = strchr(data, '|');

            if (first_b != NULL) {
                second_b = strchr(first_b + 1, '|');
                if (second_b != NULL) {
                    *first_b = '\0';
                    *second_b = '\0';

                    playlist_prepend(&pl, data, first_b + 1, atoi(second_b + 1));
                }
            }
        } else if (strncmp(line, "ins ", 4) == 0) {
            char data[300];
            char *bar1;
            char *bar2;
            char *bar3;

            strcpy(data, line + 4);

            bar1 = strchr(data, '|');
            if (bar1 != NULL) {
                bar2 = strchr(bar1 + 1, '|');
                if (bar2 != NULL) {
                    bar3 = strchr(bar2 + 1, '|');
                    if (bar3 != NULL) {
                        *bar1 = '\0';
                        *bar2 = '\0';
                        *bar3 = '\0';

                        playlist_insert_after(&pl, data, bar1 + 1, bar2 + 1, atoi(bar3 + 1));
                    }
                }
            }
        } else if (strncmp(line, "del ", 4) == 0) {
            playlist_remove(&pl, line + 4);
        } else if (strncmp(line, "up ", 3) == 0) {
            playlist_move_up(&pl, line + 3);
        } else if (strcmp(line, "q") == 0) {
            if (playlist_save(&pl, argv[1]) != 0) {
                fprintf(stderr, "Error saving playlist.\n");
            }

            playlist_free(&pl);
            return 0;
        } else {
            printf("Unknown command. Type 'p' to print.\n");
        }
    }
    playlist_free(&pl);

    return 0;
}
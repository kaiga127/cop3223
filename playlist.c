#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"


void playlist_init(Playlist *pl) {
    pl->head = NULL;
    pl->tail = NULL;
    pl->count = 0;
}

void playlist_free(Playlist *pl) {
    Song *cur = pl->head;
    while (cur) {
        Song *next = cur->next;
        free(cur);
        cur = next;
    }
    playlist_init(pl);
}

int playlist_append(Playlist *pl, const char *title, const char *artist, int duration_sec) {
    Song *new_song = malloc(sizeof(Song));

    if (new_song == NULL) {
        fprintf(stderr, "Out of memory\n");
        return -1;
    }

    strncpy(new_song->title, title, 64);
    new_song->title[64] = '\0';

    strncpy(new_song->artist, artist, 64);
    new_song->artist[64] = '\0';

    new_song->duration_sec = duration_sec;
    new_song->prev = NULL;
    new_song->next = NULL;

    if (pl->head == NULL) {
        pl->head = new_song;
        pl->tail = new_song;
    } else {
        new_song->prev = pl->tail;
        pl->tail->next = new_song;
        pl->tail = new_song;
    }

    pl->count++;

    return 0;
}

int playlist_prepend(Playlist *pl, const char *title, const char *artist, int duration_sec) {
    Song *new_song = malloc(sizeof(Song));

    if (new_song == NULL) {
        fprintf(stderr, "Out of memory\n");
        return -1;
    }

    strncpy(new_song->title, title, 64);
    new_song->title[64] = '\0';

    strncpy(new_song->artist, artist, 64);
    new_song->artist[64] = '\0';

    new_song->duration_sec = duration_sec;
    new_song->prev = NULL;
    new_song->next = NULL;

    if (pl->head == NULL) {
        pl->head = new_song;
        pl->tail = new_song;
    } else {
        new_song->next = pl->head;
        pl->head->prev = new_song;
        pl->head = new_song;
    }

    pl->count++;

    return 0;
}

int playlist_insert_after(Playlist *pl, const char *after_title, const char *title, const char *artist, int duration_sec) {
    Song *cur = pl->head;

    while (cur != NULL) {
        if (strcmp(cur->title, after_title) == 0) {
            break;
        }
        cur = cur->next;
    }

    if (cur == NULL) {
        fprintf(stderr, "Not found: \"%s\"\n", after_title);
        return -1;
    }

    Song *new_song = malloc(sizeof(Song));

    if (new_song == NULL) {
        fprintf(stderr, "Out of memory\n");
        return -1;
    }

    strncpy(new_song->title, title, 64);
    new_song->title[64] = '\0';

    strncpy(new_song->artist, artist, 64);
    new_song->artist[64] = '\0';

    new_song->duration_sec = duration_sec;

    new_song->prev = cur;
    new_song->next = cur->next;

    if (cur->next != NULL) {
        cur->next->prev = new_song;
    } else {
        pl->tail = new_song;
    }

    cur->next = new_song;

    pl->count++;

    return 0;
}

int playlist_remove(Playlist *pl, const char *title) {
    Song *cur = pl->head;

    while (cur != NULL) {
        if (strcmp(cur->title, title) == 0) {
            break;
        }
        cur = cur->next;
    }

    if (cur == NULL) {
        fprintf(stderr, "Not found: \"%s\"\n", title);
        return -1;
    }

    if (cur->prev != NULL) {
        cur->prev->next = cur->next;
    } else {
        pl->head = cur->next;
    }

    if (cur->next != NULL) {
        cur->next->prev = cur->prev;
    } else {
        pl->tail = cur->prev;
    }

    free(cur);

    pl->count--;

    return 0;
}

int playlist_move_up(Playlist *pl, const char *title) {
    Song *cur = pl->head;

    while (cur != NULL) {
        if (strcmp(cur->title, title) == 0) {
            break;
        }
        cur = cur->next;
    }

    if (cur == NULL) {
        return -1;
    }

    if (cur->prev == NULL) {
        return 0;
    }

    Song *previous = cur->prev;

    char temp_title[64];
    char temp_artist[64];
    int temp_duration;

    strcpy(temp_title, previous->title);
    strcpy(temp_artist, previous->artist);
    temp_duration = previous->duration_sec;
    strcpy(previous->title, cur->title);
    strcpy(previous->artist, cur->artist);
    previous->duration_sec = cur->duration_sec;
    strcpy(cur->title, temp_title);
    strcpy(cur->artist, temp_artist);
    cur->duration_sec = temp_duration;

    return 0;
}

void playlist_print(const Playlist *pl) {
    Song *cur = pl->head;
    int song_num = 1;

    if (cur == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    printf("= Playlist (%d songs) =\n", pl->count);

    while (cur != NULL) {
        int hour = cur->duration_sec / 3600;
        int minute = (cur->duration_sec % 3600) / 60;
        int second = cur->duration_sec % 60;

        printf("%d. %s - %s [", song_num, cur->title, cur->artist);

        if (hour > 0) {
            printf("%d:%d:%.2d", hour, minute, second);
        } else {
            printf("%d:%.2d", minute, second);
        }

        printf("]\n");

        cur = cur->next;
        song_num++;
    }
}

void playlist_print_reverse(const Playlist *pl) {
    Song *cur = pl->tail;
    int song_num = 1;

    if (cur == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    printf("= Playlist (%d songs) =\n", pl->count);

    while (cur != NULL) {
        int hour = cur->duration_sec / 3600;
        int minute = (cur->duration_sec % 3600) / 60;
        int second = cur->duration_sec % 60;

        printf("%d. %s - %s [", song_num, cur->title, cur->artist);

        if (hour > 0) {
            printf("%d:%d:%.2d", hour, minute, second);
        } else {
            printf("%d:%.2d", minute, second);
        }

        printf("]\n");

        cur = cur->prev;
        song_num++;
    }
}

int playlist_total_duration(const Playlist *pl) {
    Song *cur = pl->head;
    int total = 0;

    while (cur != NULL) {
        total += cur->duration_sec;
        cur = cur->next;
    }

    return total;
}

int playlist_load(Playlist *pl, const char *path) {
    FILE *fp = fopen(path, "r");

    if (fp == NULL) {
        fprintf(stderr, "Can't open file to read: %s\n", path);
        return -1;
    }

    char line[300];

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *title;
        char *artist;
        char *duration_str;
        int duration;

        line[strcspn(line, "\n")] = '\0';

        title = strtok(line, "|");
        artist = strtok(NULL, "|");
        duration_str = strtok(NULL, "|");

        if (title == NULL || artist == NULL || duration_str == NULL) {
            continue;
        }

        duration = atoi(duration_str);

        if (playlist_append(pl, title, artist, duration) != 0) {
            fclose(fp);
            return -1;
        }
    }

    fclose(fp);

    return 0;
}

int playlist_save(const Playlist *pl, const char *path) {
    FILE *fp = fopen(path, "w");

    if (fp == NULL) {
        fprintf(stderr, "Error saving playlist\n");
        return -1;
    }

    Song *cur = pl->head;

    while (cur != NULL) {
        fprintf(fp, "%s|%s|%d\n", cur->title, cur->artist, cur->duration_sec);
        cur = cur->next;
    }

    fclose(fp);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct Day {
    char* dayName;
    int date;
    char* activity;
};

void create(struct Day* day) {
    day->dayName = malloc(20);
    day->activity = malloc(100);

    printf("Enter the day name: ");
    scanf("%s", day->dayName);

    printf("Enter the date: ");
    scanf("%d", &day->date);

    printf("Enter the activity for the day: ");
    scanf(" %[^\n]s", day->activity);  // Reads full line including spaces
}

void read(struct Day* calendar, int size) {
    for (int i = 0; i < size; i++) {
        printf("\nEnter details for Day %d:\n", i + 1);
        create(&calendar[i]);
    }
}

void display(struct Day* calendar, int size) {
    printf("\nWeek's Activity Details:\n");
    for (int i = 0; i < size; i++) {
        printf("\nDay %d:\n", i + 1);
        printf("Day Name: %s\n", calendar[i].dayName);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n", calendar[i].activity);
    }
}

void freeMemory(struct Day* calendar, int size) {
    for (int i = 0; i < size; i++) {
        free(calendar[i].dayName);
        free(calendar[i].activity);
    }
}

int main() {
    int size;
    printf("Enter the number of days in the week: ");
    scanf("%d", &size);

    struct Day* dar=malloc(sizeof(struct Day) * size);

    read(dar, size);
    display(dar, size);
    freeMemory(dar, size);


    free(dar);

    return 0;
}

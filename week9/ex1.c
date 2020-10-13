#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct Page {
    int age, number;
};


int hit = 0, miss = 0, n, i, cur_page;


void update_frame(struct Page *frames) {
    // update ages
    int page_to_replace = 0;
    for (i = 0; i < n; i++) {
        if (frames[i].age < frames[page_to_replace].age || frames[i].number == -1)
            page_to_replace = i;
        frames[i].age >>= 1;
    }

    // check for hit
    for (i = 0; i < n; i++) {
        if (frames[i].number == cur_page) {
            hit++;
            frames[i].age = frames[i].age | (1 << 7);
            return;
        }
    }

    // otherwise it's miss
    miss++;
    frames[page_to_replace].age = (1 << 7);
    frames[page_to_replace].number = cur_page;
};


int main() {
    char *file_name = "input.txt";
    FILE *data = fopen(file_name, "r");

    // number of frames
    n = 10;

    // initialize 'n' memory frames
    struct Page *frames = malloc(n * sizeof(struct Page));
    for (i = 0; i < n; i++) {
        frames[i].age = 0;
        frames[i].number = -1;
    }

    // read all page references and try to read and update page frames
    while (fscanf(data, "%d", &cur_page) != EOF)
        update_frame(frames);

    // print his and miss rates
    printf("Total hits: %d\n", hit);
    printf("Total misses: %d\n", miss);
    printf("Hit-Miss Ratio: %f\n", (double)hit/(double)miss);

    // For n = 10:  Ratio = 0.012146
    // For n = 50:  Ratio = 0.052632
    // For n = 100: Ratio = 0.102526
    // As we increase 'n', we increase hit-miss ration, it's obvious, as there are more space for page frames --> less page faults

    return 0;
}
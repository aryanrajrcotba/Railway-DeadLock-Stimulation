#include <stdio.h>
#include <stdlib.h>

int allocate[10][10], max[10][10], need[10][10], available[10], n, r;

void input(int trainNumber, int trackNumber) {
    n = trainNumber;
    r = trackNumber;

    // Print Resource Allocation Matrix
    printf("<h3>Resource Allocation Matrix:</h3><pre>");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            // Ensure allocation does not exceed availability
            allocate[i][j] = rand() % (available[j] + 1);
            max[i][j] = allocate[i][j] + rand() % (available[j] - allocate[i][j] + 1);
            need[i][j] = max[i][j] - allocate[i][j];
            printf("%d ", allocate[i][j]);
        }
        printf("\n");
    }
    printf("</pre>");

    // Print Maximum Resource Matrix
    printf("<h3>Maximum Resource Matrix:</h3><pre>");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }
    printf("</pre>");

    // Print Need Matrix
    printf("<h3>Need Matrix:</h3><pre>");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    printf("</pre>");
}

int checkSafeState() {
    int finish[10] = {0}, safeSeq[10], work[10];
    int idx = 0;

    // Copy available resources to work array
    for (int i = 0; i < r; i++) {
        work[i] = available[i];
    }

    // Banker's Algorithm for Safe State Check
    int found;
    do {
        found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int flag = 1;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    for (int j = 0; j < r; j++) {
                        work[j] += allocate[i][j];
                    }
                    safeSeq[idx++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
    } while (found);

    if (idx == n) {
        // System is in a safe state
        printf("<div style='padding: 10px; border: 2px solid green; color: green; background-color: #d4edda; border-radius: 5px;'>");
        printf("<strong>System is in a safe state!</strong><br>Safe sequence is: <ol>");
        for (int i = 0; i < n; i++) {
            printf("<li>Train %d (Tracks: ", safeSeq[i]);
            for (int j = 0; j < r; j++) {
                printf("%d ", allocate[safeSeq[i]][j]);
            }
            printf(")</li>");
        }
        printf("</ol></div>\n");
        return 1;
    } else {
        // System is in an unsafe state
        printf("<div style='padding: 10px; border: 2px solid red; color: red; background-color: #f8d7da; border-radius: 5px;'>");
        printf("<strong>System is in an unsafe state! Deadlock is possible!</strong></div>\n");
        return 0;
    }
}

int main() {
    printf("Content-Type: text/html\n\n");
    char *data = getenv("QUERY_STRING");
    int trainNumber = 2, trackNumber = 2;
    available[0] = 3; // Example available resources
    available[1] = 2;

    if (data != NULL && sscanf(data, "trainNumber=%d&trackNumber=%d", &trainNumber, &trackNumber) == 2) {
        input(trainNumber, trackNumber);
        checkSafeState();
    } else {
        printf("<form method='get'>");
        printf("<label for='trainNumber'>Enter number of trains: </label>");
        printf("<input type='number' name='trainNumber' min='1' max='10' required><br><br>");
        printf("<label for='trackNumber'>Enter number of tracks: </label>");
        printf("<input type='number' name='trackNumber' min='1' max='10' required><br><br>");
        printf("<input type='submit' value='Check State'>");
        printf("</form>");
    }
    return 0;
}

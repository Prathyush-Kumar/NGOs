#include <stdio.h>
int main() {
    int frames[10];          
    int numFrames;            
    int numPages;            
    int pageSequence[30];    
    int pageFaults = 0;      
    int nextToReplace = 0;    
    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);
    printf("Enter the number of pages: ");
    scanf("%d", &numPages);
    printf("Enter the page reference sequence:\n");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pageSequence[i]);
    }
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }
    for (int i = 0; i < numPages; i++) {
        int currentPage = pageSequence[i];
        int pageFound = 0;
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }
        if (pageFound == 0) {
            frames[nextToReplace] = currentPage;
            nextToReplace = (nextToReplace + 1) % numFrames;
            pageFaults++;
            printf("Frame: ");
            for (int j = 0; j < numFrames; j++) {
                if (frames[j] != -1) {
                    printf("%d ", frames[j]);
                }
            }
            printf("\n");
        }
    }
    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}


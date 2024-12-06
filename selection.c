#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
	
#define WINDOW_SIZE 4
#define TOTAL_FRAMES 10

void sendFrame(int frameNumber) {
printf("Sending frame: %d\n", frameNumber);
}

bool receiveAck(intframeNumber) {
return rand() % 2;
}

int main() {
int nextFrameToSend = 0,i;
bool window[TOTAL_FRAMES] = {false};
int windowCount = 0;

while (nextFrameToSend< TOTAL_FRAMES || windowCount> 0) {
if (windowCount< WINDOW_SIZE &&nextFrameToSend< TOTAL_FRAMES) {
sendFrame(nextFrameToSend);
window[nextFrameToSend] = false;
nextFrameToSend++;
windowCount++;
        }
usleep(1000000); // Sleep for 1 second

for ( i = 0; i< TOTAL_FRAMES; i++) {
if (!window[i] &&receiveAck(i)) {
printf("Acknowledgment received for frame: %d\n", i);
window[i] = true;
windowCount--;
            }
        }

for ( i = 0; i< TOTAL_FRAMES; i++) {
if (!window[i]) {
printf("Resending frame: %d\n", i);
sendFrame(i);
            }
        }
    }
return 0;
}




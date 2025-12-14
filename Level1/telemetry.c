#include <stdio.h>
#include <math.h>
#include <windows.h>

unsigned char checksum(const char *s) {
    unsigned char chk = 0;
    while (*s) chk ^= *s++;
    return chk;
}

// Windows millisecond timer
unsigned long millis() {
    return GetTickCount();
}

int main() {
    float t = 0.0;

    while (1) {
        float ax = sin(t);
        float ay = cos(t);
        float az = 1.0;

        float gx = 0.1f * sin(t);
        float gy = 0.1f * cos(t);
        float gz = 0.05f;

        float alt = 100.0f + t;
        float temp = 25.0f + 0.5f * sin(t);

        char payload[200];
        sprintf(payload,
            "L1,%lu,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f",
            millis(), ax, ay, az, gx, gy, gz, alt, temp
        );

        unsigned char chk = checksum(payload);

        printf("$%s*%02X\n", payload, chk);

        t += 0.1f;
        Sleep(50);   // 50 ms ? 20 Hz
    }
}

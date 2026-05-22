#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "flag";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        int i =0, num = 0, flag = 1;
            while(buffer[i] != '\n') {
                if (buffer[i] > 57 || buffer[i] < 48) {
                    flag = 0;
                    break;
                }

                buffer[i] -= '0';
                num *= 10;
                num += buffer[i];
                i++;
            }

            if (flag) {
                sum += num;
            } else {
                fprintf(stderr, "invalid input %s", buffer);
            }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}

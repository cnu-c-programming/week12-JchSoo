#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 3)
        return 0;

    FILE* fp_src = fopen(argv[1], "r");
    FILE* fp_dst = fopen(argv[2], "w");

    while (!feof(fp_src))
    {
        fprintf(fp_dst, "%c", fgetc(fp_src));
    }

    fclose(fp_src);
    fclose(fp_dst);
    
}


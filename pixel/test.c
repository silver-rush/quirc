#include <stdio.h>

#include "test.h"
#include "../lib/quirc_internal.h"
#include "../lib/quirc.h"

int main(int argc, char* argv[]){
    printf("Hello!\n");

    for (int i=0; i<100; i++){
        for (int j=0; j<100; j++){
            im[i][j] *= 255;
        }
    }

    struct quirc reader;
    quirc_resize(&reader, 100, 100);

    int x, y;
    quirc_begin(&reader, &x, &y);
    printf("X: %d Y:%d\n", x, y);
    reader.image = &im[0][0];

    quirc_end(&reader);

    int count = quirc_count(&reader);

    printf("Number of qr codes: %d\n", count);

    struct quirc_code code;
    struct quirc_data data;

    quirc_extract(&reader, 0, &code);
    quirc_decode_error_t err = quirc_decode(&code, &data);

    printf("Error: %d\n", err);

    printf("Read: %d\n", data.version);
    printf("Read: %d\n", data.ecc_level);
    printf("Read: %d\n", data.mask);
    printf("Read: %d\n", data.data_type);

    printf("Read: %d\n", data.payload_len);

    return 0;
}

#include <stdlib.h>
#include <string.h>
void swap(void *vp1, void *vp2, size_t size) {
    char *buff = (char *) malloc(size);
    memcpy(buff, vp2, size);
    memcpy(vp2, vp1, size);
    memcpy(vp1, buff, size);
    free(buff);
}

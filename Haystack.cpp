#include <stdio.h>
#include <string.h>

int main() {
    char haystack[] = "This is a sample haystack.";
    char needle[] = "sample";

    
    char *result = strstr(haystack, needle);

    if (result != NULL) {
        printf("Needle found at index: %ld\n", result - haystack);
    } else {
        printf("Needle not found.\n");
    }

    return 0;
}

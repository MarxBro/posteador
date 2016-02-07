#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main( int argc, char *argv[] )  {
    if( argc > 2 ) {
        printf("Demasiados Argumentos.\n");
        exit (1);
    } 
    if (argc < 2) {
        printf("Necesito UN Argumento: la URL a getear!.\n");
        exit (1);
    }

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

        /*Evitar errores relacionados con dominios https*/
#ifdef SKIP_PEER_VERIFICATION
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif

#ifdef SKIP_HOSTNAME_VERIFICATION
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    exit(0);
}

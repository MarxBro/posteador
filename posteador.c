#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

/*function_pt(void *ptr, size_t size, size_t nmemb, void *stream){*/
/*printf("%d", atoi(ptr));*/
/*}*/

int main( int argc, char *argv[] )  {
    if( argc > 3 ) {
        printf("Demasiados Argumentos.\n");
        exit (1);
    } 
    if (argc < 3) {
        printf("Necesito Dos Argumentos: el dominio y el string a postear.\n");
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

        /* POST data */ 
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, argv[2]);

        /*funcion callback, para imprimir lo que sea que la pag devolvio-*/
        /*curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, function_pt);*/

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

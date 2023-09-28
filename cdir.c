#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#define MAX_LINE_LENGTH 1000
 
int main(int argc, char *argv[]) {
    FILE *textfile;
    char *line = malloc(MAX_LINE_LENGTH * sizeof(char));
	long response_code;

    textfile = fopen(argv[2], "r");
    if(textfile == NULL)
        return 1;
 	int c = 0;
   while(fgets(line, MAX_LINE_LENGTH, textfile)){
		char *x = malloc(MAX_LINE_LENGTH * sizeof(char));
		CURL *curl = curl_easy_init();
		strcpy(x, argv[1]);
		strtok(line, "\n");
		strcat(x, line);
		curl_easy_setopt(curl, CURLOPT_URL, x);
	    curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
        curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
		curl_easy_cleanup(curl);
		c++;
 		printf("%i %s %ld\n",c, x ,response_code);
    }
    free(line);
    fclose(textfile);
    return 0;
}

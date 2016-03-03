#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <curl/curl.h>


int main() {

	CURL *curl;
	CURLcode curl_res;
	CURLINFO info;
	long http_code;
	double c_length;  

  FILE *tmp;

  tmp=fopen("/tmp/google_index.html", "w");
  if(tmp==NULL) {
    printf("ERROR to open file /tmp/google_index.html\n");
    exit(2);
  }

  printf("init curl session\n");
	curl = curl_easy_init();

  printf("set url to download\n");
	curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.de/index.html");

  printf("set file handler to write\n");
	curl_easy_setopt(curl, CURLOPT_WRITEDATA,  tmp);

  printf("download the file\n");
  curl_res = curl_easy_perform(curl);
  if(curl_res==0) {
    printf("file downloaded\n");
  } else {
    printf("ERROR in dowloading file\n");
    fclose(tmp);
    curl_easy_cleanup(curl);
  }

  printf("get http return code\n");
  curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
  printf("http code: %lu\n", http_code);

  printf("get size of download page\n");
  curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &c_length);
  printf("length: %g\n", c_length);


  printf("END: close all files and sessions\n");
  fclose(tmp);
  curl_easy_cleanup(curl);

  return 0;
}

# coding libcurl in C


* [`curl.haxx.se`](http://curl.haxx.se/)
* [`download`](http://curl.haxx.se/download.html)
* [`libcurl`](http://curl.haxx.se/libcurl/)
* [`all about libcurl with C`](http://curl.haxx.se/libcurl/c/)


You must include:

```c
<curl/curl.h>
```

compile
```bash
gcc libcurl1.c -o libcurl1 -lcurl
```


important structures:

```c
CURL *curl;
CURLcode curl_res;
CURLINFO info;
```

Start a libcurl easy session
```c
curl = curl_easy_init();
```

[`see more info`](http://curl.haxx.se/libcurl/c/curl_easy_init.html)

set options for a curl easy handle
```c
curl_easy_setopt(CURL *handle, CURLoption option, parameter);
```

CURLOPT_WRITEDATA Data pointer to pass to the file write function
```c
curl_easy_setopt(curl, CURLOPT_WRITEDATA, tmp);
```

tmp: FILE handle

set proxy
```c
curl_easy_setopt(curl, CURLOPT_PROXY, pxy);
```

Perform a file transfer
```c
curl_easy_perform(CURL * handle );
```

End a libcurl easy session
```c
curl_easy_cleanup(curl);
```

set an url
```c
curl_easy_setopt(curl, CURLOPT_URL, url);
```

set file handle, where the data get writed
```c
curl_easy_setopt(curl, CURLOPT_WRITEDATA, tmp);
```

download the page
```c
curl_res = curl_easy_perform(curl);
```

get http status code
```c
curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
```

get size of downloaded page
```c
curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &c_length);
```

sample: libcurl1.c
```c
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
```

```bash
./libcurl1

init curl session

set url to download

set file handler to write

download the file

file downloaded

get http return code

http code: 200

get size of download page

length: 6969

END: close all files and sessions
```


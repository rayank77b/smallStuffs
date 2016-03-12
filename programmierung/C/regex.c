#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <regex.h>


int main() {

  int err;
	char err_str[200];
	char results[500];

  int i,j,k=0;

	regex_t preg;
	regmatch_t pmatch[100];

  char *buf="blub blub blub@googlemail.com adslfku asdf@gmail.com oasduf";

	if( (err = regcomp(&preg, "\\b[A-Za-z0-9._%+-]+@(gmail|googlemail)+\\.[a-zA-Z]{2,4}\\b", REG_EXTENDED)) != 0)  {
			printf("regcomp error\n");
			return -1;
	}

	if( (err = regexec(&preg, buf, preg.re_nsub, pmatch, 0)) != 0)  {
    regerror(err, &preg, err_str, 200);
    printf("%s\n",err_str);
    return -1;
  } else {
    for(i = 0; i < preg.re_nsub; i++) {
      if(pmatch[i].rm_so == -1) continue;
      for(j = pmatch[i].rm_so; j < pmatch[i].rm_eo; j++) 
        results[k++] = buf[j];
      results[k] = '|';
      results[++k] = '\0';
    }
  }

  printf(">> results: %s\n", results);

	regfree(&preg);


return 0;
}

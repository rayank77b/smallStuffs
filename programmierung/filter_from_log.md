# filtern some patern in file /var/log/syslog

Challenge:

filtern some patern in file /var/log/syslog

and print it out

Shell:
```bash
fgrep usb /var/log/syslog
```

Java:
```java
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class JavaFilters {
 public static void main(String[] args) {
  String path="/var/log/syslog";
  try {
   BufferedReader input =  new BufferedReader(new FileReader(path));
   
   String line;
   try {
    Pattern p = Pattern.compile("dhclient");
    while (( line = input.readLine()) != null){
     Matcher m = p.matcher(line);
     if(m.find())
      System.out.println("found:: "+line);
    }
   } catch (IOException e) {
    e.printStackTrace();
   }
  } catch (FileNotFoundException e) {
   e.printStackTrace();
  }
 }
}
```

Scala:
```scala
import scala.io.Source
import java.util.regex._

var p = Pattern.compile("usb")

for ( line <- data-blogger-escaped-br="" data-blogger-escaped-getlines="" data-blogger-escaped-log="" data-blogger-escaped-source.fromfile="" data-blogger-escaped-syslog="" data-blogger-escaped-var="">  var m = p.matcher(line);
  if( m.find ) 
    print("found::" + line)
} 
```

Perl:
```perl
#!/usr/bin/perl

open(IN, "/var/log/syslog") or die "canot open file: $!";

@lines = <IN>;
close IN;

foreach $line(@lines) {
  if( $line =~ /dhclient/) {
    print "found:: $line";
  }
}
```

Ruby:
```ruby
#!/usr/bin/ruby

file = File.new("/var/log/syslog", "r") or die "canot open file"

while (line = file.gets)
  if ( line =~ /usb/ )
    print "found:: "+line
  end
end
```

Python:
```python
#!/usr/bin/python

try: 
  f = open('/var/log/syslog', 'r')

  for line in f.readlines():
    if( "usb" in line ): 
      print("found:: %s"%line)

except: 
  print "error in file"
```

PHP:
```php
<?php
$file = "/var/log/syslog";
if (file_exists($file)) {
  $lines = file($file);
  foreach ($lines as $line_num => $line) 
    if( preg_match("/usb/", $line) ) 
      echo "$line";
}
?>
```

C:
```c
#include 
#include 
#include 
#include 
#include 

FILE *file = NULL; 

int main(int argc, char **argv)
{
  char line[1024];
  int err;
  char err_str[200];
  char results[500];
  
  regex_t preg;
  regmatch_t pmatch[100];
  
  if( (regcomp(&preg, argv[1], 0)) != 0)  {
    printf("regcomp error\n");
    return -1;
  }
  
  if((file = fopen("/var/log/syslog", "r")) != NULL) {
    while (!feof(file)){
      fgets(line, 1024, file);

      if( regexec(&preg, line, preg.re_nsub, pmatch, 0) == 0)  {
          printf("found:: %s", line);
      }  
    }
  }

  regfree(&preg);
  return 0;
}
```

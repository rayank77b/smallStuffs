# PHP Samples/Tutorials

```php
$in = fopen("php://stdin","r");

while ($l =$fgets($in, 1024)) {
  $a = preg_split('/\s+/', $l);
  while(list($k, $v) = each($a)) {
...
```
```php
foreach($c as $k=> $v) ...
```

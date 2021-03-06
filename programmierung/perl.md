# Perl Sampels/Tutorials

join an array to scalar
```perl
my $evilwordsregexp = join('|', @evilwords);

foreach my $file (@testitems) {
```

nuke everything after the first space (#comment)
```perl
$file =~ s/\s.*$//;
next if (!$file); # skip null entries
```

open the file for reading
```perl
if (open (FILE, $file)) { 
close (FILE);
```

and go through the file line by line
```perl
while (my $file_line = <FILE>) { 
```

found an evil word
```perl
if ($file_line =~ /($evilwordsregexp)/i) { 
```

get page with perl
```perl
sub getpage($$) {
    my $link = shift;
    my $base = shift;

    my @site_content;

    my $ua = LWP::UserAgent->new();
    $ua->agent('Mozilla/5.0');

    my $request = HTTP::Request->new('GET', $link);
    my $response = $ua->request($request);
    print "Retrieving http-page...\n";
    if ( $response->is_error() ) {
        $urls{$base}{'error'} = "Error code : ". $response->code() . "\n" .
        "Error message: " . $response->message() . "\n";
        return ();
    }
    else {
        #print Dumper($response);
        @site_content = split /\n/, $response->content();
        $urls{$base}{'lasturl'} = $response->request->uri;
        return @site_content;
    }
}
```

```perl
($sec, $min, $hour, $day, $mon, $year, $wday, $yday, $isdst)=localtime(time());
print scalar(localtime()); # > Fri Dec 21 11:11:30 2006
```

gibt keine leezreilen und zeilen mit "---" oder mehr aus
```perl
print unless ( /^\s+$/ or /-{3,}/ );
```

sucht nach kapazietaet
```perl
$pfad="/proc/acpi/battery/BAT0/state";
if(/remaining capacity: *?(\d*?) mAh/) {
print $1;
```

eine mail senden
```perl
use Email::Send;
send SMTP=> <<'__MESSAGE__', $host;
To: anfrit00@fht-esslingen.de
From: foo@example.com

bla bla
__MESSAGE__
```

```perl
perl -e 'print "$_\n" foreach(@INC);'
/etc/perl
/usr/local/lib/perl/5.8.8
/usr/local/share/perl/5.8.8
/usr/lib/perl5
/usr/share/perl5
/usr/lib/perl/5.8
/usr/share/perl/5.8
/usr/local/lib/site_perl
```

formatprobe
```perl
open (CON_LIST, '>-') or die " open error\n";
$i=1; $key="klasst"; $result=0.23; $erg=23;

write CON_LIST;

close CON_LIST;

format CON_LIST =
@> @<<<<<<<<<<<<<<< @>>>> = @<<<<<<
$i, $key, $result, $erg
.
```

zu datenbank verbinden (mysql)
```perl
use DBI();

$dbhost="localhost";
$dbname="mysql";
$dbuser="root";
$dbpass="";
```

verbinden
```perl
my $dbh = DBI->connect("DBI:mysql:database=$dbname;host=$dbhost",
$dbuser, $dbpass, {'RaiseError' => 1});
my $sth = $dbh->prepare("SELECT host, user, Password FROM user"); # anfrage
$sth->execute(); # anfrage senden

while (my $user = $sth->fetchrow_hashref()) { # daten als hash holen
# $user ist eine hash referenz
print "HOST: ".$user->{'host'}."\nUSER: ".$user->{'user'}."\nPASS: ".$user->{'Password'}."\n\n";

}
$dbh->disconnect(); # verbindung zu db schliessen
```

einfaches parameter options
```perl
use Getopt::Std;
getopts("vr:", \%options);
print "v-> ".$options{'v'}."\n";
print "r-> ".$options{r}."\n";
#./test.pl -v -r bla
#v-> 1
#r-> bla
```

dateien globen
```perl
$path=".";
while (<$path/*.pl>) {
print $_."\n";
}
# gibt alle dateinamen *.pl aus
```

socket
```perl
my $sock = new IO::Socket::UNIX (Peer => $ARGV[0], Type => SOCK_STREAM); # socket
print $sock $query; # senden
my $response = <$sock>; # empfangen
close $sock;
```

einfacher server
```perl
use IO::Socket;
$socket=new IO::Socket::INET (LocalHost=>$ARGV[0],
LocalPort=>6677,
Proto=>'tcp',
Listen=>5, Reuse=>1,);
# max 5 stueck, reuse=1 benutze den port wieder
die "new socket error: $!" unless $socket;

while($cli=$socket->accept()) { # client verbindet
print $cli "Hallo, \n";
$cli->flush(); # flushen
close($cli); # und tschuess
}
close($socket);
```

server
```perl
user IO::Socket;
$ss=new IO::Socket::INET(LocalPort=>2345, Listen=>$SOMAXCONN, Proto=>'tcp', Reuse=>1);
# loop on incomming connections
while($sc=$ss->accept()) {
$data=<$sc>; # empfang
print $sc "bla"; # senden
$sc->close();
}
close($ss);
```

client
```perl
$sc=new IO::Socket::INET(PeerAddr=>$hostname, PeerPort=>2345, Type=>SOCK_STREAM, Proto=>'tcp');
# .. aehnlich server

# donot use IO::Socket::INET this package is defined in IO::Socket
```

pack unpack
```perl
my $query = pack("L L N N S S", 0x2343defe, 0x12345678,
2343343, 1111323, $ARGV[2], $ARGV[4]);
my ($magic, $id, $type, $genre, $detail, $dist, $link, $tos, $fw,
$nat, $real, $score, $mflags, $uptime) =
unpack ("L L C Z20 Z40 c Z30 Z30 C C C s S N", $response);
```

alle modulen *.pm ausgeben
```perl
perl -e 'print "$_\n" foreach(@INC);' | while read f; do find $f -name \*.pm ; done
```

inplace editieren, scritpname:pr2.orig
```perl
@ARGV=("pr2.orig");
$^I=".bak"; # backup name
$n=0;
while(<>) {
print "$n: $_";
$n++;
}
```

pipe
```perl
open IN, "cat mail.pl |" or die "cat??";
print while();
close IN;
$cmd1="wc";
$cmd0='tr -s " " " " ';
open SEND, "| $cmd0 | $cmd1" or die "bla";
print SEND "daasa sdfklasdf jkaldskjfaslkdj ";
close SEND;
open SEND, "| tr '[a-z]' '[A-Z]'";
print SEND "hello"; # leitet die ausgabe ueber pipe nach tr
close SEND;
$encoder="/usr/bin/uuencode";
open SEND, "| $encoder stdout" or die "encoder";
print SEND "dies ist eine probe";
close SEND;
```

cgi
```perl
use CGI qw/:standard/;
print header,
start_html('-title'=>"Statistik"),
p("Die letzten Tagen"),
h1("Blabla bla");
```

datei locken
```
use IO::File;
use Fcntl qw(:flock);

my $fh=new IO::File(">probe.txt") or die "IO::File\n";

flock $fh, LOCK_EX;
print "get flock datei\n";
print $fh "bla bla";

$eing=<>;

flock $fh, LOCK_UN;
$fh->close;
```

ftp benutzen
```perl
use Net::FTP;

$host="dx40";
$user="ray";
$pass='';

$ftp=Net::FTP->new($host) or die "Net::FTP->new error:$!\n";
$ftp->login($user, $pass) or die "login error: $!\n",$ftp->message;
$ftp->binary();
$ftp->cwd("/home/ray/daten") or die "cwd error\n";

@alle=$ftp->ls();
#print foreach(@alle);
$ftp->get($_) foreach(@alle);

$ftp->quit();
```


holt n-mails von gmx.net ab
```perl
use Net::POP3;
$host='pop.gmx.net';
$user='userbla@gmx.net';
$pass='passbla23';
$ort='/home/ray/daten/popmails/mail';

$datum=time();
open OUT, ">>$ort$datum" or die "kann nicht mail oeffnen: $! \n";

($mail=Net::POP3->new($host)) or die "error open $host: $!\n";

$lo=$mail->login($user, $pass);
die "login error: $!\n" unless defined $lo;
print "Login: $user OK\n";
if($lo) {
foreach $nr (1..10) {
print "Mail nr $nr\n";
$inhalt=$mail->get($nr);
print OUT @$inhalt;
$mail->delete($nr);
}
}
close(OUT);
$mail->quit();
```

wandelt ip in int um
```perl
use Net::IP;
my $src = new Net::IP ("127.0.0.1") or die (Net::IP::Error());
print $src->intip()."\n";
```

read a gif file
```perl
$A="latest.gif";
open A or die "$A: $!";
read A, $b, 1024;
@c=unpack "C4A40(A/A)4", $b;
open OUT, ">gifinfo.txt";
print OUT for(@c);
close OUT;
```

zeit
```perl
@monat=qw(jan feb mar apr mai jul jun aug sep okt nov dec);
my ($s,$m,$h,$d,$mo,$y,@r)=localtime();
print "$h:$m:$s\n";
print "$d ".$monat[$mo]." ", 1900+$y,"\n";
```
```perl
$|=1; # ausgabe nicht puffern
```


persistente variablen(hash)
```perl
use GDBM_File; # persistenter hash
use Fcntl; # O_CREAT, O_RDWR usw
```
persistenten hash oeffnen
```perl
tie(%MEM, GDBM_File, $pfile, O_CREAT|O_RDWR, 0644) or
die "cannot open $pfile";
```
binden den hash MEM an die Datei pfile, ueber GDBM Interface
der hash MEM erscheint als normaler hash im speicher, liegt aber auf der platte
```perl
$MEM($url)="bla"; # schreiben
$d=$MEM('pla'); # lesen
untie(%MEM); # pers. hash schliessen
```

web
```perl
use LWP::UserAgent;
$ua=LWP::UserAgent->new(); # user agent erzeugen
$request=HTTP::Request->new('GET', $url); # url festlegen
$response=$ua->request($request); # netzzugriff ausfuehren
if($response->is_error()) { ... } # $response->is-success
$response->content()

use LWP::Simple;
$doc=get 'http://www.google.de';

perl -MLWP::Simple -e 'getprint "ftp://...";'

use LWP::Simple;
mirror($url, $localfile);


use HTML::Parse;
use HTML::FormatText;
$html=parse_htmlfile($htmlfile);
$formatter=new HTML::FormatText(leftmargin=>0, rightmargin=>70);
print OUT $formater->format($html);
```

checksume berechnen
```perl
$chksum=unpack("%16C*", $dat);
```

Ping
```perl
user Net::Ping;
$po=Net::Ping->new();
if($po->ping($hostname)) {
    print "$hostname da";
}
$po->close();
```

FTP
```perl
use Net::FTP;
login($servername, $passwort);
#ascii, binary
cwd($dir); # dir($dir) pwd quit
$dir=$ftp->dir(); # return a refernce
foreach(@$dir) print "$_\n";
#
$ftp = Net::FTP->new("some.host.name", Debug => 0)
or die "Cannot connect to some.host.name: $@";
$ftp->login("anonymous",’\-anonymous@’)
or die "Cannot login ", $ftp->message;
$ftp->cwd("/pub")
or die "Cannot change working directory ", $ftp->message;
$ftp->get("that.file")
or die "get failed ", $ftp->message;
$ftp->quit;
# SEE perldoc Net::FTP
```

mail
```perl
use Mail::Send;
$mail=Mail::Send->new();
$mail->to($addr);
$mail->cc($copy_to_addr);
$mail->bcc($blind_copy);
$mailhandle=$mail->open();
print $mailhandle << END;
bla bla
....
END;
$mailhandle->close(); # send mail
```

MIME
```perl
use MIME::Lite;
$msg=MIME::Lite->new(From=>$fromaddr, To=>$toaddr, Subject=>'bla',
Type=>'multipart/mixed');
$msg->attach(Type=>'TEXT', Encoding=>'7bit', Data=>'bla bla');
$msg->attach(Type=>'image/gif', Encoding=>'base64', Path=>'bild.gif', Filename=>'bild.gif');
# convert message to string
$str=$msg->as_string();
$msg->send();

# decoding MIME
use MIME::Parser;
$mime=new MIME::Parser;
$mime->read(\*INPUT); # geoffnete Datei
```

SMTP
```perl
use Net::SMTP;
$ms=new Net::SMTP($hostname, Debug=>1,);
$ms->mail($from_addr);
$ms->to($addr);
$ms->data($data); # in data steht auch der subject
```

POP3
```perl
use Net::POP3;
$ms=new Net::POP3($hostname);
$msg_cnt=$ms->login($usrename, $passwd);
$headers=$ms->list(); # reference
foreach $message(keys(%$headers)) {
    $header=$ms->top($message);
}
$message=$ms->last();
$contents=$ms->get($message);
$ms->quit();
```

DBM
```perl
dbmopen(%dbhash, "filename", 0666);
$dbhash{'name'}="bla bla";
print $dbhash{'any'};
dbmclose(%dbhash);

while(($key, $val)=each(%dbhash)) {
    print ...
}
```

```perl
use Fcntl;
use SDBM_File;
use Config;
$flags=O_CREAT|O_RDWR;
tie(%dbhash, 'SDBM_File', 'sdmtest', $flags, 0666) or die "cannot open database $!";
$dbhas{localtime()}="bla..";
untie(%dbhash);
```

tie bindet eine variable zu etwas, hier zu einer datenbank klasse
tie(var, classname, file, flags, mode)
var: %hash, @array, $scalar, HANDLE

tying scalar, array, filehandle, hash when call 'tie', perl execute proper constructor
array ->TIEARRAY
handle->TIEHANDLE
hash ->TIEHASH
scalar->TIESCALAR

TIESCALAR classname, list
FETCH this
STORE this, val
DESTROY this

```perl
package Myscalar;

sub TIESCALAR {
my ($class)=$_[0];
my ($self)=0;
return (bless(\$self, $class));
}
sub FETCH {
my($reference_to_self)=$_[0];
return ($$reference_to_self);
}
...
1;
```

an object is a reference
```perl
tie($myscalar, 'Myscalar');
$myscalar=55;
untie($myscalar);
```

TIEARRAY classname, list
FETCH this, index
STORE this, index, value
DESTROY this

TIEHANDLE classname, list
PRINT this, list
PRINTF this, list
READLINE this # called by <>
GETC this
READ this, list
DESTROY this

TIEHASH classname, list
FETCH this, key
STORE this, key, value
EXISTS this, key
DELETE this, key
CLEAR this
FIRSTKEY this
NEXTKEY this, lastkey
DESTROY this

store $v=$hash{'key'};
exists if(exists($hash{'key'})) { ..
delete delete $hash{'key'};


Tie::Hash, Tie::StatHash

sub STORE{ $_[0]->{$_[1]}=$_[2]; }
sub FIRSTKEY{ my $a=scalar keys%{$_[0]};
each%{$_[0]} }
sub CLEAR{ %{$_[0]}=() }
# %{..} anonyme hash


package Tie::Stdhash;
@ISA=qw(Tie::Hash); # used to speify which baseclass a new class inherits from
# Tie::StdHash inherits from Tie::Hash
sub STORE { ... } # override the STORE method


#Databases
use DBI;
@drivers=DBI->available_drivers();
$db=DBI->connect('dbi:mSQL:test:localhost);
$db->disconnect();
$cursor->execute();
if($DBI::err) { .. error }


perldoc DBI::FAQ
# extract the data
while(@val=$cursor->fetchrow()) { .. }

use vars qw(@ISA); # pragma to predeclare global variable names (obsolete)


# Zlib
use Compress::Zlib;
binmode STDOUT;
my $gz=gzopen(\*STDOUT, "wb");
while(<>) {
$gz->gzwrite($_);
}
$gz->gzclose();

$gzerrno!=Z_STREAM_END; Z_OK

$gz->gzreadline($_);
$gz->gzread($buffer);

my $x=inflateinit();
($output, $status)=$x->inflate(\$input);
my $x=deflateinit();
($o, $s)=$x->deflate($_);
$x->flush();


use Bla;
$o=Bla::funct() # oder
use Bla qw(funct);
$o=funct();


push @arr, $var; # append $var to @arr
pop @arr; # get the latest element and remove it

use File::Basename;
$path="/usr/lib/perl5/Net/Ping.pm";
@suf=".pm";
($basename, $dir, $suffix)=fileparse($path, @suf);
# Ping /usr/lib...


use Config;
%Config; # -which include a lot of inormation about the configuration of Perl
if($Config{osname}=~/^Windows/) ..

use File::Compare; # compare 2 files
$result=compare($file1, $file2); # 0 equal 1 diff -1 errror

use File::Copy;
copy($sourcefile, $destfile);
move($srcfile, $dstfile);

#Installing new Module
perl Makefile.PL
make
make install



# Image with GD
use GD;
$im=new GD::Image(100,100);
$back=$im->colorAllocate(100,150,255);
$im->fill(1,1,$back);
$outfile=">"."name.gif";
print OUT $im->gif;
$black=$im->colorAllocate(0,0,0);
$im->string(gdLargeFont, 30,40, $message);
# stringUp(..) rotate 90°
$font=gdMediumBoldFont;
$char_width=$font->width;
$char_height=$font->height;
$len=length($message);
$im->line($x, $y, $x2, $y2, $color);
$im->transparent($back);


/\binder\b/ # wortgrenze 'inder' aber kein 'rinder'

$arg=shift(@ARGV);
while(defined $arg) { ... }

$h{"bla"}="bla";
@val=values(%h);

<=> cmp -1 less 0 equal 1 greater

while(true) {}   until(false){}

if()  unless()

local($v)  are local for temporary value of a gloabal variable

# modifying parameters
$a=1;
inc($a);  # 2
sub inc {
 $_[0]+=1;
}

@a=(1,2,3..);
mod(*a);
sub mod {
  local (*la)=@_;
  @la=reverse(@la);
}

print((split " ",$_)[0]."\n") while(<>);
# split im listenkontext, erster element

perl -ane 'print $F[0];'  # analog
# -a autosplit, (split $_ into @F
# -n while loop

while(<>) { print if /head/; }


# cgi html
#!/usr/bin/perl -wT
print "Content-type: text/plain \n\n";
# -T taint Modus, Benutzereingaben in Quarantaene

HTML::Template;
use strict;
use warnings;
HTML::Embperl;
HTML::Mason;

Template;
HTML::Template;
DBI;
CGI;
CGI::Carp qw(fatalsToBrowser);

$q=new CGI;
foreach($q->param) { .. # param GET/POST parameters

$template=new HTML::Template(filename=>'addressbuch_kontakt.html');
$template->param(personen=>\@_pers)


db 
$dbh->selectrow_hashref('SELECT ..');
      selectrow_array( .... );

if(exists $bla)
if( not exiss $bla)


splice: removes and replaces elements in an array
splice(ARRAY, OFFSET, LENGTH, LIST);


%SIG  # signal handles hash
sub handler { ... }
$SIG{'INT'}='handler';
$SIG{'INT'}='DEFAULT';


srand(time() | $$);   # zeit doer pid einlesen
$l=int(rand(10));

if/ [^123]0 /  # 10 20 30

x?? schaltet greedinessaus
\b word bounding
alternation /Ab|cd/   /(ma|pa)+/

$1 $2 ergebnisse der gruppierung
\1 \2  suchmuster
(?: ..) turn off capturing -> $1  void


V  filehandle
$v scalar
@v array
%v hash
&v  subroutine
*v everything named v

$s.$s2;
$s.=$s2; #concate
$sx4; #4 mal


s::mp('bla');
packages s;
sub mp {
  print ("@_\n");
}

use File::Basename;
look for File/Basename.pm


jeder Modul muss mit 1; beenden

BEGIN { require "bla.p"; }

pragmas: use integer;  no integer;

calling methods (OOP)
$obj->meth($param);
meth $obj $param;

```perl
sub meth {
  my $self=shift;  # refernz auf obj
  ...
}

# constructor
sub new {
  my $self={}; # hash anonymous referenz
  $self->{ATTRIB1}=undef;
  ...
  # make Referenz
  bless($self);
  return $self;
}

#Destructor
sub DESTROY {
 ...
}
```

```perl
sub u {
  my $self=shift;
  if(@_) {
    $self->{U}=shift; 
  }
  return $self->{U};
}
$o->('bla');
print $o->u,"\n";

#!!not 
print "$o->u\n";
```


use Cwd;
$cur_dir=cwd;

use File::Basename;
(...)=fileparse(..);

use Config; 
%Config

$perldoc -l copy

druckt den Pfad aus File::Find

www.pewrl.com/CPAN

HTML::LinkExtor, URI::URL

head() links()

```shell
perl Makefile.PL
make
make install
```

perl -cw  p.pl  #  -c nur pruefen, nicht ausführen
                #  -w zusätzliche Warnungen ausgeben

use strict;  # direktive verwenden, alle variablen muessen mit my beginnen.

immer 
```perl
#!/usr/bin/perl -w  # starten !

for my $z (1..10) {
    print "$z \n";
}

my $n;
$n=<>;  # von stdin oder der dateiename (bei start
# angegeben perl t.pl bla.txt) einlesen
chomp $n; # zeilenende entfernen

while (defined($z=<>)) { ....
# oder
while (my $z=<>) { ....

$z = <STDIN>;  # nur von stdin einlesen

@ARGV=("test.dat");
while (my $z=<>) { # liest von test.dat ein.

$^I=".bak"; # inplace editieren, kopie wird als .bak gespeichert
# print "..."; wird in originaldatei umgeleitet.


print sprintf("%-6d", $.).$zeile;
```



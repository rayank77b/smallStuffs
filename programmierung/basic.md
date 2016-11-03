# Stuff and Info about Basic

```basic
PRINT CHR$(34); "Hallo,"; CHR$(34); ", sagte sie."
```
Variablen
INTEGER, LONG, CURRENCY, SINGLE und
DOUBLE, STRING


Array
```basic
DIM Liste(1 TO 64) AS INTEGER
DIM Tabelle%(1 TO 16, 1 TO 4)
DIM Wuerfel(1 TO 4, 1 TO 4, 1 TO 4) AS INTEGER

ein zweidimensionales Array deklarieren, 
das nur die Zeilen 8 bis 15 und nur die Spalten 1980 bis 2000 enthält
```basic
DIM Geschaeftsbericht(8 TO 15, 1980 TO 2000) AS CURRENCY
```

Ein Record ist ein Verbund von Elementen verschiedenen Typs.
```basic
TYPE GeschenkTyp
    Name AS STRING * 20
    Wert AS CURRENCY
END TYPE

TYPE Geburtstagstyp
    Name AS STRING * 50
    Tag AS INTEGER
    Monat AS INTEGER
    Jahr AS INTEGER
    AnzahlGeschenke AS INTEGER
    Geschenk(99) AS GeschenkTyp
END TYPE

DIM Geburtstag AS Geburtstagstyp
Geburtstag.Monat = 11
PRINT Geburtstag.Geschenk(10).Wert


IF bedingung THEN
    block
ELSE
    block
END IF

SELECT CASE variable
    CASE w1: block
    CASE w2: block
    ...
    CASE ELSE: block
    END SELECT

DO WHILE/UNTIL bedingung
    block
LOOP


DO
    block
LOOP WHILE/UNTIL bedingung



DIM Taste AS STRING * 1
DO
    Taste = UCASE$(INPUT$)
    SELECT CASE Taste
    CASE "1": DatenErfassen
    CASE "2": DatenAusgabe
    CASE "3": ListenAusdruck
    CASE "0": EXIT DO
LOOP



REM Kommentar
' auch ein Kommentar

CONST DateiZuGross = 1 , Gefunden = 2 , NichtGefunden = 3


DIM DateiName(1 TO MaxDateien) AS STRING , Pfadangabe AS STRING


PRINT "Bitte geben Sie eine Dateibezeichnung an (* und ? erlaubt): " ;
LINE INPUT DateiBezeichnung


FUNCTION ExtrahierePfad (Bezeichnung AS STRING) AS STRING
    DIM Zaehler AS INTEGER
    FOR Zaehler = LEN(Bezeichnung) TO 1 STEP –1
        ' von hinten : oder \ suchen
        SELECT CASE ASC(MID$(Bezeichnung , Zaehler , 1))
            CASE 92 , 58
                ExtrahierePfad = LEFT$(Bezeichnung , Zaehler)   ' wenn gefunden: alles bis
                                                                ' hier ist Pfadangabe
                EXIT FUNCTION
        END SELECT
    NEXT
    ExtrahierePfad = ""          ' Dann bleibt's leer
END FUNCTION

PRINT FORMAT$(AnzahlDateien) ; " Dateien passen."


 String                 $
   Integer
      Regular             %
      Long                &
   Floating Point
      Single-precision    !
      Double-precision    #


DO: Zeichen = UCASE$(INPUT$(1)): LOOP UNTIL INSTR("JN" , Zeichen)


IF VAL(Gewaehlt.Caption) = 0 THEN
    MSGBOX "Sie müssen mindestens eine Datei auswählen." , 0 , "Fehler"
    DateiBezeichnung.SETFOCUS
ELSEIF LEN(Suchen.Text) = 0 THEN
    MSGBOX "Sie müssen einen Suchtext angeben." , 0 , "Fehler"
    Suchen.SETFOCUS
ELSE



print "main: application running"

sub on_init( ) constructor
	print "starting: before main"
end sub

sub on_exit( ) destructor
	print "exiting: bye!"
	sleep
end sub


./constructor 
starting: before main
main: application running
exiting: bye!


? "Blub"
? kann man anstelle von PRINT verwenden

' mehrere anweisungen, in einer zeile
anweis1: anweis2: anweis3

dim var1 as string
input "geben sie was ein: ", var1
? var1



type MyType
	bar as integer
	declare sub printMe( ) 
	declare static sub printThis( byref x as MyType )
end type

sub MyType.printMe( ) 
	print bar
end sub

sub MyType.printThis( byref x as MyType )
	print x.bar
end sub

dim as MyType x
x.printMe( )
MyType.printThis( x )



' Loops
for i as integer = 0 to 9
	print i; " ";
next
print

dim as integer i = 0

do
	print i; " ";
	i += 1
loop while i < 4

do
	print i; " ";
	i += 1
loop until i = 7

while i < 10
	print i; " ";
	i += 1
wend

print

print "press ESC to exit"
while inkey() <> chr(27)
	sleep 20, 1
wend





'' TYPEs and UNIONs (unlimited nesting):

type OtherUDT
	x as integer
	y as integer
end type

type MyType
	a as short
	b as integer
	c as long
	d as OtherUDT
	union
		e as double
		f as single
		g as OtherUDT
	end union
	h as byte
end type

union MyUnion
	a as integer
	b as longint
	c as double
	my as MyType
end union



function AddNumbers( a as integer, b as integer ) as integer
	return a + b
end function

sub hello( )
	print "hello"
end sub

declare sub myprint( num as integer )

	'' Code outside any procedures is the main part of the program
	hello( )
	print AddNumbers( 1, 1 )
	myprint 5

sub myprint( num as integer )
	print num
end sub



SUB MaxAlloc (Zeichenfolge AS STRING , Bezeichnung AS STRING)
    ON LOCAL ERROR RESUME NEXT
    PRINT "Speicher für " ; Bezeichnung ; ": " ;
    FOR i% = 1000 TO 31000 STEP 1000
        Zeichenfolge = SPACE$(i%)
        IF ERR THEN PRINT FORMAT$(i% - 1000) ; : EXIT FOR
    NEXT
    IF ERR = 0 THEN PRINT "31000" ;
        PRINT " temporäre Strings:" ; FRE("")
END SUB



CLS
int1% = -24300
long1& = 344353452
str1$ = "Gespeicherter String"
single1! = 34.43424
double1# = 342834.3452524234924#
PRINT "Nun werden die Werte der einzelnen Variablen der Reihe nach ausgegeben:"
PRINT "Integer-Variable: ", int1%
PRINT "Long-Variable: ", long1&
PRINT "String-Variable: ", str1$
PRINT "Single-Variable: ", single1!
PRINT "Double-Variable: ", double1#


PRINT "Hier wird ein Zeilenumbruch";    ' Semikolon verhindert Zeilenumbruch

' Informationen in tabellarischer Form darstellen:
PRINT "Spalte 1", "Spalte 2", "Spalte 3", "Spalte 4"
PRINT , , , "Spalte 4"




CLS
COLOR 12 	' Farbwert 12 = Hellrot
PRINT "Dieser Text wird in roter Schrift ausgegeben..."



CLS
COLOR 4,7
PRINT "Dunkelrote Schrift, weisser Hintergrund"
PRINT ""
COLOR 23,0
PRINT "Schwarzer Hintergrund, weisse blinkende Schrift"

LOCATE Zeile, Spalte
PRINT TAB(Spalte);
SLEEP 10	' 10 Sekunden warten

RANDOMIZE TIMER
Zufallszahl = RND
Zufallszahl = FIX(RND * 100)    ' FIX schneidet Nachkommastellen des Ergebnisses ab


OPEN Datei FOR Zugriffsmodus AS Zugriffsbezeichner
OPEN "C:\file01.txt" FOR OUTPUT AS 1
PRINT #Zugriffsbezeichner, Text
PRINT #1, "Dieser Text wird in eine Textdatei geschrieben"
CLOSE 1 


OPEN "C:\file01.txt" FOR INPUT AS 1
LINE INPUT #1, buffer$
CLOSE 1























































































































































































































































































































































































































































v



















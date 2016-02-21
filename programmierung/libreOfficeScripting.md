# Libre Office (tutorials/codesnipets).


* [`https://help.libreoffice.org/Basic/Programming_with_Basic`](https://help.libreoffice.org/Basic/Programming_with_Basic)
* [`https://help.libreoffice.org/Basic/Organizing_Libraries_and_Modules`](https://help.libreoffice.org/Basic/Organizing_Libraries_and_Modules)
* [`http://www.linux.com/learn/tutorials/380813-introduction-to-openoffice-macros`](http://www.linux.com/learn/tutorials/380813-introduction-to-openoffice-macros)
* [`http://www.open-of-course.org/courses/mod/url/view.php?id=826`](http://www.open-of-course.org/courses/mod/url/view.php?id=826)

```basic
REM  Comments
```

Variables
```basic
Option Explicit         To force declaration of variables

Dim a$ 	                Declares the variable "a" as a String   up to 65,535 characters
Dim a As String 	    Declares the variable "a" as a String
Dim a$, b As Integer 	Declares one variable as a String and one as an Integer
Dim c As Boolean 	    Declares c as a Boolean variable that can be TRUE or FALSE

Dim Variable%           % Integer    -32768 to 32767
Dim Variable As Integer

Dim Variable&           & Long       -2147483648 to 2147483647
Dim Variable As Long

Decimal variables can take positive or negative numbers or zero. Accuracy is up to 29 digits.

Dim Variable!           ! Single     3.402823 x 10E38 to 1.401298 x 10E-45
Dim Variable As Single

Dim Variable#           # Double     1.79769313486232 x 10E308 to 4.94065645841247 x 10E-324
Dim Variable As Double

Dim Variable@           @ Currency  -922337203685477.5808 to +922337203685477.5807  
Dim Variable As Currency

Dim Variable As Date
```

Types: Numeric, String, Boolean,  Object
```basic
Dim Text$(20) 	        21 elements numbered from 0 to 20
Dim Text$(5,4) 	        30 elements (a matrix of 6 x 5 elements)
Dim Text$(5 To 25) 	    21 elements numbered from 5 to 25
Dim Text$(-15 To 5) 	21 elements (including 0), numbered from -15 to 5

Const ConstName=Expression

Subroutines, Functions
```basic
Sub SubName(Parameter1 As Type, Parameter2 As Type,...)
Dim LocalVariable as Type
    Program code
End Sub

Rem calling
SubName(Value1, Value2,...)

Function FunctionName(Parameter1 As Type, Parameter2 As Type,...) As Type
    Program code
FunctionName=Result
End Function

Variable=FunctionName(Parameter1, Parameter2,...)

Library.Module.Macro()
```
a parameter is always passed by reference. 
if you want by value: use
```basic
Result = Function(ByVal Parameter)
```

```basic
Global VarName As TYPENAME      The variable is valid as long as the LibreOffice session lasts.
Public VarName As TYPENAME      The variable is valid in all modules.
Private VarName As TYPENAME     The variable is only valid in this module.
Dim VarName As TYPENAME         The variable is only valid in this module.  
```

Enforce private variables to be private across modules by setting CompatibilityMode(true).

Static VarName As TYPENAME      Saving Variable Content after Exiting a SUB or FUNCTION

Specifying the Return Value Type of a FUNCTION
Function WordCount(WordText As String) As Integer


* [`Python in Libre Office`](http://tmtlakmal.wordpress.com/2013/08/11/a-simple-python-macro-in-libreoffice-4-0/)


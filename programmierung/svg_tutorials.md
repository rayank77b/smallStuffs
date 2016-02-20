# SVGFIG

[`Plotting Tutorial`](https://code.google.com/p/svgfig/wiki/PlottingTutorial)

```python
from svgfig import *

hacks=[]
hacks["inkscape-text-vertical-shift"] = True

c = Curve( "t, t**2", -2, 2 )
p = Plot( -2, 2, -2, 6, c )
s = p.SVG()
s.save()           # tmp.svg

Plot( -2, 2, -2, 6, c ).SVG().save()
Plot( -2, 2, -2, 6, Curve( "t, t**2", -2, 2 ) ).SVG().save()
```

```python
c1 = Curve( "t, t**2", -2, 2 )
c2 = Curve( "t, t**3", -2, 2, stroke = "blue" )
Plot(-2, 2, -2, 6, c1, c2).SVG().save()


c = Curve("t, t**2", -2, 2)
e = Ellipse(0, 0, 1, 2, 1, stroke="blue")
Plot(-2, 2, -2, 6, c, e).SVG().save()


c = Curve("t, t**2", -2, 2)
Plot(-2, 2, -2, 6, c, arrows="myarrows").SVG().save()


c = Curve("t, t**2", -2, 2)
Frame(-2, 2, -2, 6, c).SVG().save()


 = Curve("t, t**2", -2, 2)
xa = XAxis(-2, 2, 0)
mywin = window(-2, 2, -2, 6, x=10, width=80)
Fig(c, xa, trans = mywin).SVG().save()


c = Curve("t, t**2", -2, 2)
Plot(-2, 2, -2, 6, c, yticks=-20).SVG().save()
Plot(-2, 2, -2, 6, c, yticks=-7).SVG().save()


c = Curve("t, t**2", -2, 2)
Plot (-2, 2, -2, 6, c, yticks = {2:"two", 3:"three", 4:"four", 5:"five"} ).SVG().save()
```

```python
from svgfig import *
from math import *
import random

angle_axis = LineAxis(5, 0, 5, 2*pi, 0, 2*pi)
angle_axis.text_start = -2.5
angle_axis.text_angle = 180.
angle_axis.ticks = [x*2*pi/8 for x in range(8)]
angle_axis.labels = lambda x: "%g" % (x*180/pi)
angle_axis.miniticks = [x*2*pi/8/9 for x in range(8*9)]

radial_axis = XAxis(0, 5, aty=pi/2)
radial_axis.text_start = 5
radial_axis.text_angle = 90.
radial_axis.ticks = range(5)

points = [(max(0.5, random.gauss(2.5, 1)), random.uniform(-pi, pi), max(0.1, random.gauss(0.3, 0.1))) for i in range(10)]
xerr = XErrorBars(points)
yerr = YErrorBars(points)
dots = Dots(points, make_symbol("name", stroke="black", fill="red", stroke_width="0.25pt"))
Fig(Fig(angle_axis, radial_axis, xerr, yerr, dots, trans="x*cos(y), x*sin(y)")).SVG(window(-6, 6, -6, 6)).inkview()
```

```python
import svgfig

# read in the "SVGFig" text I typed and converted into paths
text = svgfig.load("svgfig_logo_source.svg")

# find my objects (this is all meant to be an interactive process)
print text
textpath = svgfig.pathtoPath(text[1])
textpath.attr = {"stroke":"none", "fill":"black"}

# First, get it out of the weirdo units I drew it in, and into something symmetric
symm = svgfig.Fig(textpath, trans=svgfig.window(240, 320, 235, 275, x=-1, y=-1, width=2, height=2, flipy=False))

# Next, be sure I can draw it normally, taking it from symmetric coordinates into a 200x100 page
# (This draws to the screen)
svgfig.canvas_outline(svgfig.Fig(symm, trans=svgfig.window(-1, 1, -1, 1, width=200, flipy=False)).SVG(), viewBox="0 0 200 100").inkview()

# The semicircular axis, with arrows
curveaxis = svgfig.CurveAxis("0.6*(-0.98+cos(t)), sin(t)", -1.2, 1.2, ticks=21, miniticks=81, labels=False, \
                             arrow_start="arrowstart", arrow_end="arrowend", stroke_width="0.5pt")

# The background grid: a nice light blue
thegrid = svgfig.Grid(-1, 1, -1.2, 1.3, ticks=20, stroke=svgfig.rgb(0.8,0.8,1.))

# Transform the text and the grid together, but not the semicircular axis
text_and_grid = svgfig.Fig(thegrid, svgfig.Fig(symm, trans="x-0.1,y"), trans="x + 2*x*y**2, y*(1+1.5*x+4*x**2)")

# Combine them all and convert to SVG (note the nested Figs)
svg = svgfig.Fig(text_and_grid, curveaxis, trans=svgfig.window(-0.8, 0.7, -1, 1.1, width=200, flipy=False)).SVG()
print svg # it's complicated, but clear that our background grid is svg[0,0]

# Define a radial gradient and a clipping rectangle in SVG
# (I learned how to do this by drawing it in Inkscape and looking at the output)
SVG = svgfig.SVG

defs = SVG("defs", \
           SVG("radialGradient", SVG("stop", stop_color="white", stop_opacity=0, offset="0%") \
                               , SVG("stop", stop_color="white", stop_opacity=1, offset="100%") \
                               , cx=100, cy=50, r=100, gradientTransform="translate(0,25) scale(1,0.5)" \
                               , gradientUnits="userSpaceOnUse", id="theRadGrad"), \
           SVG("clipPath", SVG("rect", x=0, y=0, width=200, height=100), id="theClip") \
           )

# add a rectangle with this gradient after the grid before the other artwork
# svg[0, 0, "stroke"] = "url(#theRadGrad)"
svg[0].append(SVG("rect", x=0, y=0, width=200, height=100, stroke="none", fill="url(#theRadGrad)"))
       
# add the gradient definitions before it
svg[0].prepend(defs)

# clip the first group (containing the grid lines)
svg[0].attr["clip-path"] = "url(#theClip)"

svgfig.canvas(svg, viewBox="0 0 200 100").save("svgfig_logo.svg")
```

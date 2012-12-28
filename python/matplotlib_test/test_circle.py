#!/usr/bin/env python
# -*- coding: utf-8 -*-
import pylab
pylab.axes()
cir = pylab.Circle((0,0), radius=0.75,  fc='none')
pylab.gca().add_patch(cir)
cir = pylab.Circle((.5,.5), radius=0.25, alpha =.2, fc='b')
pylab.gca().add_patch(cir)
pylab.axis('scaled')
pylab.show()

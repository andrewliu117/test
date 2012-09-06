#!/usr/bin/env python
# -*- coding: utf-8 -*-

class test:
	def __init__(self):
		self.i = 1
	
	def inc(self):
		j = 0
		while j < 10:
			self.i += 1
			yield self
			print self.i
			j += 1

if __name__ == "__main__":
	t = test()
	for obj in t.inc():
		print obj.i
		obj.i += 10

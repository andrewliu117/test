#!/usr/bin/env python
# -*- coding: utf-8 -*-

from django.http import HttpResponse
import datetime

def current_datetime(request):
	now = datetime.datetime.now();
	html = "<html><body> It's now %s.</body></html>" % now
	return HttpResponse(html)

def hours_ahead(request, offset):
	offset = int(offset);
	now = datetime.datetime.now();
	html = "<html><body> It's now %s.<br/>" % now
	dt = datetime.datetime.now() + datetime.timedelta(hours=offset)
	part2 = "In %s hours(s), it will be %s. </body></html>" % (offset, dt)
	html += part2
	return HttpResponse(html)


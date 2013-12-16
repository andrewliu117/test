#!/usr/bin/env python
# -*- coding: utf-8 -*-

from django.http import HttpResponse
import datetime

def current_datetime(request):
	now = datetime.datetime.now();
	html = "<html><body> It's now %s.</body></html>" % now
	return HttpResponse(html)

def hours_ahead(request, offset):
	now = datetime.datetime.now();
	html = "<html><body> It's now %s.<br/>" % now
	dt = datetime.datetime.new() + datetime.timedelta(hours=offset)
	html += "In %s hours(s), it will be %s. </body></html>" % (offset, dt)
	return HttpResponse(html)


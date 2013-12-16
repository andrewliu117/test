#!/usr/bin/env python
# -*- coding: utf-8 -*-

from django.http import HttpResponse
import datetime

def current_datetime(request):
	now = datetime.datetime.now();
	html = "<html><body> It's now %s.</body></html>" % now
	return HttpResponse(html)

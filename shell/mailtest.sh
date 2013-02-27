#!/bin/bash

{
	echo "From: andrew.liu@qq.com"
	echo "title: this is title"
	echo "this is content"

} 
{
	echo "mime-version: 1.0
	from: comeol<comeol@gmail.com>
	cc: comeol <test@mama.com>
	subject: helo
	Content-Type: text/plain;charset=\"gb2312\"
	this is content"
}

#MAILFROM="alarm_extract@alarm.com"
#MAILTO="liuhongjiang@snda.com jiangling@snda.com"
#CONTENT="content.html" # content.html是文件名
#SUBJECT="我是标题"
#(echo "MIME-Version: 1.0"
#echo 'Content-Type: text/html; charset="utf-8"'
#echo "Content-Disposition: inline"
#echo "From: $MAILFROM"
#echo "To: $MAILTO"
#echo "Subject: this is subject $SUBJECT"
#cat $CONTENT) | /usr/sbin/sendmail -t
#MAILFROM="alarm_extract@alarm.com"
#MAILTO="liuhongjiang@snda.com jiangling@snda.com"
#CONTENT="content.html" # content.html是文件名
#SUBJECT="我是标题"
(echo "MIME-Version: 1.0"
echo 'Content-Type: text/html; charset="utf-8"'
echo "Content-Disposition: inline"
echo "From: alarm_extract@alarm.com"
echo "To: liuhongjiang@snda.com"
echo "Subject: this is subject 我是标题"
cat content.html) | /usr/sbin/sendmail -t




# HOW to install django on ubuntu

1. 在系统中安装好easy\_install，该程序python的包管理工具。待安装好后，可以使用该工具安装上Django，安装easy\_install:
	
	```
	dengc@ubuntu:~$ sudo apt-get install python-setuptools（安装easy_install）
	```
	
	可以使用下面的命令检查是否安装成功
	
	```
	dengc@ubuntu:~$ easy\_install -h(检测是否安装成功)
	```

	如果显示该命令参数的帮助信息，表示安装成功。

2. 使用easy\_install安装Django:

	```
	dengc@ubuntu:~$ easy_install django
	```

	可以使用以下命令检查是否安装成功

	```
	dengc@ubuntu:~$ python(进入python交互式环境)
	>>> import django
	>>> django.VERSION
	如果显示类似于以下的信息，表示安装成功。
	>>> (1, 3, 0, 'final', 0)
	```

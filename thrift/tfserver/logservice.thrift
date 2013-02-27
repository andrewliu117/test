# getlogs
# url_list:支持多个url
# return value map:
#    key 是url
#	 value 是一个list，list中存放了日志
#
# getlistlogs 支持输出insert日志上下附近的日志
# url_list 支持多个url
# listlen 上下日志的条数
# return value map:
#    key 是url
#	 value 是一个list，list中存放了日志
 


service logservice {
    map<string,list<string>> getlogs(1:required list<string> url_list)
    map<string,list<string>> getlistlogs(1:required list<string> url_list, 2:i32 listlen)
}

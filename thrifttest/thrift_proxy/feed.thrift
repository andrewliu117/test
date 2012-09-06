/*
 * url      : the url to be fetched                 | valid url string          | required without default value
 * freq     : check frequency(unit: second)         | positive integer > 10     | default value is 10 seconds
 * max_fetch: the max fetch count                   | positive integer or "inf" | default value is 1
 * expire   : the expire time(unit: second)         | positive integer or "inf" | default value is 86400 seconds
 * depth    : crawl depth from this url             | integer belongs [1,10]    | default value is 0
 * schedule : fetching schedule level               | integer belongs [1,10]    | default value is 5
 * method   : crawl methond                         | must be "get" or "chk"    | default value is "get"
 * retry_num: retry time if fetching failed         | integer belongs [1,10]    | default value is 3
 * blob     : reserved field for non-crawler usage  | json string without "\n"  | default value is ""
 */
struct LinkMeta {
    1:string url,
    2:i32 freq,
    3:string max_fetch,
    4:string expire,
    5:i32 depth,
    6:string schedule,
    7:string method,
    8:i32 retry_num,
    9:string blob
}

service feed{
    /*
     * set a fetch list of LinkMeta
     */
    bool putFetchList( 1:required list<LinkMeta> url_list);

    /*
     * set a fetch list of urls, using default values of all other fields
     */
    bool putDefaultFetchList( 1:required list<string> url_list);

    /*
     * add regular expression for filtering outlinks extracted from fetched pages
     */
    bool addOutlinkFilter( 1:required list<string> reg_expr_list);

    /*
     * clean all regular expressions already exists
     */
    bool cleanOutlinkFilter();
}

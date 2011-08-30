<?php
$keywords = $_GET['keywords'];
$num = intval($_GET['num']);
$page = intval($_GET['page']);
if($page == NULL || $page<1)
{
    $page = 1;
}
if($num == NULL || $num<1)
{
    $num = 10;
}
$startpos = $num*($page-1);
if( strcmp(substr($keywords, 0,1),"0")>=0
    && strcmp(substr($keywords,0,1),"9")<=0)
{
    //echo "code";
    $sql = "select corp_code,corp_corp,corp_industry from tb_Z_Corp 
    where corp_code like \"$keywords%\" order by corp_code limit $startpos,$num";
    //echo $sql;
}
else{
    //echo "name";
    $sql = "select corp_code,corp_corp,corp_industry from tb_Z_Corp 
    where corp_corp like \"$keywords%\" order by corp_code limit $startpos,$num";
    //echo $sql;
}

$host = "192.168.1.135";
$user = "root";
$pass = "111111";
$dbname = "yc_db";
$link = @mysql_connect($host,$user,$pass) or die("error");
@mysql_select_db($dbname,$link) or die("error2");
@mysql_query("set names utf8",$link);
$result = @mysql_query($sql,$link);

$json = 'getstock_callback({"body":[';
$stock = @mysql_fetch_array($result);
while ($stock)
{
    if($i++)
    {
        $json = $json.",";
    }
    $json = $json."{\"stockcode\":\"$stock[corp_code]\",
    \"stockname\":\"$stock[corp_corp]\",
    \"industry\":\"$stock[corp_industry]\"}";
    $stock = @mysql_fetch_array($result);
}
$json = $json.']})';

echo $json;
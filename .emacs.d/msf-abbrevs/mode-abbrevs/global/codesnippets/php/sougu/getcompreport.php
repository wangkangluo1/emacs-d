<?php
$stockcode = $_GET['stockcode'];
if($stockcode==NULL || strlen($stockcode)!=6)
{
    echo 'getcompreport_callback({
            "body":[],
            "err":"请传递正确的股票代码参数"
        }
    )';
    return;
}
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
$sql = "select agency,researcher,title,url,date from tb_s_report 
    where code=\"$stockcode\" order by date desc limit $startpos,$num";


$host = "192.168.1.135";
$user = "root";
$pass = "111111";
$dbname = "yc_db";
$link = @mysql_connect($host,$user,$pass) or die("error");
@mysql_select_db($dbname,$link) or die("error2");
@mysql_query("set names utf8",$link);
$result = @mysql_query($sql,$link);

$json = 'getcompreport_callback({"body":[';
$report = @mysql_fetch_array($result);
$i = 0;
while ($report)
{
    
    if($i++)
    {
        $json = $json.",";
    }
    $json = $json."{\"stockcode\":\"$stockcode\",
    \"agency\":\"$report[agency]\",
    \"researcher\":\"$report[researcher]\",
    \"title\":\"$report[title]\",
    \"url\":\"$report[url]\",
    \"date\":\"$report[date]\"}";
    $report = @mysql_fetch_array($result);

}
$json = $json.']})';

echo $json;
<?php
$stockcode = trim($_GET['stockcode']);
$num = intval(trim($_GET['num']));
$page = intval(trim($_GET['page']));
if($page == NULL || $page<1)
{
    $page = 1;
}
if($num == NULL || $num<1)
{
    $num = 10;
}
$startpos = $num*($page-1);
    $sql = "select 
    code,
    update_date,
    publish_date,
    reason,
    total_equity,
    circulating_a,
    managers,
    limited_a,
    circulating_b,
    limited_b,
    circulating_h,
    country,
    country_fr,
    territory_fr,
    territory_fqr,
    raiser_fr,
    general_fr,
    strategic,
    fund,
    turn,
    staff,
    preferred
    from tb_s_structure 
    where code=$stockcode order by publish_date desc limit $startpos,$num";

$host = "192.168.1.135";
$user = "root";
$pass = "111111";
$dbname = "yc_db";
$link = @mysql_connect($host,$user,$pass) or die("error");
@mysql_select_db($dbname,$link) or die("error2");
@mysql_query("set names utf8",$link);
$result = mysql_query($sql,$link);

$json = 'getstructure_callback({"body":[';
$stock = @mysql_fetch_array($result);
while ($stock)
{
    if($i++)
    {
        $json = $json.",";
    }
    $json = $json."{\"code\":\"$stock[code]\",
    \"update_date\":\"$stock[update_date]\",
    \"publish_date\":\"$stock[publish_date]\",
    \"reason\":\"$stock[reason]\",
    \"total_equity\":\"$stock[total_equity]\",
    \"circulating_a\":\"$stock[circulating_a]\",
    \"managers\":\"$stock[managers]\",
    \"limited_a\":\"$stock[limited_a]\",
    \"circulating_b\":\"$stock[circulating_b]\",
    \"limited_b\":\"$stock[limited_b]\",
    \"circulating_h\":\"$stock[circulating_h]\",    
    \"country\":\"$stock[country]\",
    \"country_fr\":\"$stock[country_fr]\",
    \"territory_fr\":\"$stock[territory_fr]\",
    \"territory_fqr\":\"$stock[territory_fqr]\",
    \"raiser_fr\":\"$stock[raiser_fr]\",
    \"general_fr\":\"$stock[general_fr]\",
    \"strategic\":\"$stock[strategic]\",
    \"fund\":\"$stock[fund]\",
    \"turn\":\"$stock[turn]\",
    \"staff\":\"$stock[staff]\",
    \"preferred\":\"$stock[preferred]\"}";
        
    $stock = @mysql_fetch_array($result);
}
$json = $json.']})';

echo $json;
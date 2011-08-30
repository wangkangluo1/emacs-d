<?php
function string_deal($text)
{
    $text = str_replace("\n","",$text);
    $text=str_replace("\n","",$text);
    $text=str_replace("\r","",$text);
    $text=str_replace("\r\n","",$text);
    $text=str_replace("\"","\\\"",$text);
    return $text;
}
?>

<?php
function checkVS($str)
{
    //返回结果为1只有数字,2只有字符,3两者都有
    $a=0;
    $b=0;
    for($i=0; $i<strlen($str);$i++)
    {
        $v=ord(substr($str,$i,1));
        if($v>=48 and $v<=57)
        {
            $a=1;
        }
        else
        {
            $b=2;
        }
    }
return $a+$b;
}
?>

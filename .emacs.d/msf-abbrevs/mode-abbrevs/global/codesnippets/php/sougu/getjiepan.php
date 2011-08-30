<?php
    include 'strings.php';
    include 'data.php';
    include 'stringsdeal.php';
    $sets = array (    //可设置参数
             "page_info" => array (
                  "Page" => 1,
                  "Pagesize" => 10 
              ),
             "table" => "tb_r_jiepan"
                       );
    $inputs = get_inputs($sets);
    $data = new mysql_obj();
    $result = $data->start($sets['table'], $inputs, -1, -1, $inputs['condition']);
    print_back($result['result'],$result['count']);    
    $data->close($result['result']);




function print_back($result, $count)
{
    $page_count = mysql_num_rows($result);
    print_head($count);
    if(mysql_num_rows($result) != 0)
    {
        mysql_data_seek($result, 0);
        $i = 0;
        while ($row=mysql_fetch_row($result))
        {
            echo "{";

            $text = string_deal($row[0]);
            echo "\"title\":\"".$text."\",";

            $text = string_deal($row[1]);
            echo "\"time\":\"".$text."\",";

            $text = string_deal($row[2]); 
            echo "\"summary\":\"".$text."\"";
            if($i != $page_count-1) 
            {
                echo "},";
            }
            else
            {
                echo "}";
            }
            $i++;
        }
    }
    else
    {
        print_content();
    }
    echo "],
         \"err\":\"\"
}
)";
}

function print_head($count)                                                                                                                                                      
{
    echo "getjiepan_callback(
    {
        \"result\":";
   if($count != -1)
   { 
    echo $count;
   }
    echo ",\"body\":[";
}

function print_content()
{
            echo "{";
            echo "\"title\":\"\",";
            echo "\"post_time\":\"\",";
            echo "\"detail\":\"\"";
            echo "}";
}

function print_error($string)
{
        echo "],\"err\":\"";
        if($string != -1)
        {
            echo $string;
        }
        echo "\"})";

}




    function get_inputs($sets)
    {
        $inputs = array (    //可设置参数
             "stockcode",
             "num",
             "page",
             "orderby" => "time",
             "condition" => array(
                  "where" => 0,
                  "orderby" => 1
                  ) 
              ); 
        switch($_SERVER['REQUEST_METHOD'])
        {
            case 'GET': $the_request = &$_GET; break;
            case 'POST': $the_request = &$_POST; break;
        }


        $inputs['num'] = $sets['page_info']['Pagesize'];
        if(isset($the_request['num']))
        {
            if((checkVS($the_request['num']) == 1))
            {
                $inputs['num'] = $the_request['num'];
            }
        }

        $inputs['page'] = $sets['page_info']['Page'];
        if(isset($the_request['page']))
        {
            if((checkVS($the_request['page']) == 1))
            {
                $inputs['page'] = $the_request['page'];
            }
        } 
        return $inputs;
    }
?>

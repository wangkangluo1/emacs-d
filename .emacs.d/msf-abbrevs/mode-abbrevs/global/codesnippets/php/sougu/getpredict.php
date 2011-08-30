<?php
    include 'data.php';
    include 'strings.php';
    include 'stringsdeal.php';
    $sets = array (    //可设置参数
             "page_info" => array (
                  "Page" => 1,
                  "Pagesize" => 10 
              ),
             "table" => "tb_a_predict"
                       );
    $inputs = get_inputs($sets);
    $data = new mysql_obj();
    $result = $data->start($sets['table'], $inputs, -1, -1, -1);
    print_back($result['result']);    

    $data->close($result['result']);




function print_back($result)
{
    $count = mysql_num_rows($result); 
    echo "getpredict_callback(
    {
        \"result\":".$count.
            ",\"body\":[";
        //$hasresult = mysql_fetch_array($result);
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
                echo "\"post_time\":\"".$text."\",";
                echo "\"detail\":\"\"";
                if($i != $count-1) 
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
            echo "{";
            echo "\"title\":\"\",";
            echo "\"post_time\":\"\",";
            echo "\"detail\":\"\"";
            echo "}";
        }

        echo "],
             \"err\":\"\"
    }
    )";
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


        if((is_null($the_request['num']) == TRUE) or (empty($the_request['num']) == TRUE))
        {
            $inputs['num'] = $sets['page_info']['Pagesize']; 
        }
        else
        {
            $inputs['num'] = $the_request['num'];
        }

        if((is_null($the_request['page']) == TRUE) or (empty($the_request['page']) == TRUE))
        {
            $inputs['page'] =  $sets['page_info']['Page'];
        }
        else
        {
            $inputs['page'] = $the_request['page'];
        }

        $inputs['orderby'] = $the_request['orderby'];
        return $inputs;
    }
?>

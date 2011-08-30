<?php
    include 'strings.php';
    include 'data.php';
    include 'stringsdeal.php';
    $sets = array (    //可设置参数
             "page_info" => array (
                  "Page" => 1,
                  "Pagesize" => 10,
                  "orderby" => "closing_date" 
              ),
             "table" => "tb_l_trans"
                       );

    $inputs = get_inputs($sets);
    if($inputs != 0)
    {
        $data = new mysql_obj();
        $result = $data->start($sets['table'], $inputs, "securities_code", $inputs['stockcode'], $inputs['condition']);
        print_back($result['result'], $result['count']);    
        $data->close($result['result']);
    }
    else
    {
        print_string("please confirm your inputs!");
    }

function print_string($string)
{
    print_head(-1);
    print_content();
    print_error($string);
}


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
                echo "\"closing_date\":\"".$text."\",";

                $text = string_deal($row[1]);
                echo "\"securities_code\":\"".$text."\",";

                $text = string_deal($row[2]);
                echo "\"abbreviation\":\"".$text."\",";

                $text = string_deal($row[3]);
                echo "\"closing_price\":\"".$text."\",";

                $text = string_deal($row[4]);
                echo "\"trading_volume\":\"".$text."\",";

                $text = string_deal($row[5]);
                echo "\"turnover\":\"".$text."\",";

                $text = string_deal($row[6]);
                echo "\"buyer\":\"".$text."\",";     

                $text = string_deal($row[7]);
                echo "\"saler\":\"".$text."\"";
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
        print_error(-1);
}


function print_head($count)
{
    echo "getbigdeal_callback(
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
            echo "\"closing_date\":\"\",";
            echo "\"securities_code\":\"\",";
            echo "\"abbreviation\":\"\",";
            echo "\"closing_price\":\"\",";
            echo "\"trading_volume\":\"\",";
            echo "\"turnover\":\"\",";
            echo "\"buyer\":\"\",";       
            echo "\"saler\":\"\""; 
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
             "orderby" => "closing_date",
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

        if(isset($the_request['stockcode']))
        {
            if((checkVS($the_request['stockcode']) != 1))
            {
                return 0;
            }
            else
            {
                $inputs['condition']['where'] = 1;
                $inputs['stockcode'] = $the_request['stockcode'];
            }
        }
        else
        {
            return 0;
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

        if(isset($the_request['orderby']))
        {
            if(($the_request['orderby'] == "closing_date") or ($the_request['orderby'] == "closing_price") or ($the_request['orderby'] == "trading_volume") or ($the_request['orderby'] == "turnover"))
            {
                $inputs['orderby'] = $the_request['orderby'];
            }       
        }




        //$inputs['orderby'] = $the_request['orderby'];
        return $inputs;
    }
?>

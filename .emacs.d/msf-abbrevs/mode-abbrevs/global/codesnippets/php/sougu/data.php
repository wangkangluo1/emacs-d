<?php
class mysql_obj{
   
    protected   $mysql = array (    //可设置参数
         "ip" => "222.68.223.242",
         "usr" => "root",
         "pwd" => "root",
         "database" => "yc_db"
      ) ;     
    function start($table, $inputs, $row, $key, $condition)
    {
        $back = array(
                "result",
                "count"
                );
        $link = mysql_connect($this->mysql['ip'], $this->mysql['usr'], $this->mysql['pwd']);
        mysql_query("set names ’utf8’ ");  
        mysql_query("set character_set_client=utf8");  
        mysql_query("set character_set_results=utf8");
        mysql_select_db($this->mysql['database'], $link);
        $limits =  $inputs['num'];
        $start = ($inputs['page'] - 1)*$inputs['num'];
        $orderby = $inputs['orderby'];
        if(($condition['orderby'] == 1) and ($condition['where'] == 1))
        {
            $result_count = mysql_query("SELECT * FROM $table  where $row=$key", $link);
            $count = mysql_num_rows($result_count);
            mysql_free_result($result_count);
            $result = mysql_query("SELECT * FROM $table  where $row=$key  order by $orderby desc LIMIT $start,$limits", $link);
        }
        elseif(($condition['orderby'] == 0) and ($condition['where'] == 1))
        {
            $result_count = mysql_query("SELECT * FROM $table  where $row=$key", $link);
            $count = mysql_num_rows($result_count);
            mysql_free_result($result_count);
            $result = mysql_query("SELECT * FROM $table  where $row=$key LIMIT $start,$limits", $link);
        }
        elseif(($condition['orderby'] == 1) and ($condition['where'] == 0))
        {
            $result_count = mysql_query("SELECT * FROM $table", $link);
            $count = mysql_num_rows($result_count);
            mysql_free_result($result_count);
            $result = mysql_query("SELECT * FROM $table order by $orderby desc LIMIT $start,$limits", $link);
        }
       
        else
        {
            $result_count = mysql_query("SELECT * FROM $table", $link);
            $count = mysql_num_rows($result_count);
            mysql_free_result($result_count);
            $result = mysql_query("SELECT * FROM $table LIMIT $start,$limits ", $link);
        }
        $back['result'] = $result;
        $back['count'] = $count;
        return $back;
    }


    function close($result)
    {
        mysql_free_result($result);
        // 关闭连接
        mysql_close();  
    }
}
?>

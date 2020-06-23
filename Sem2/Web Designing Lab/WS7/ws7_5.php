<?php
    $month_temp = "67, 60, 68, 69, 71, 68, 72, 80, 63, 64, 89, 63, 81, 76, 73,
                   68, 72, 72, 75, 65, 74, 63, 67, 65, 64, 62, 73, 75, 81, 79";
    $temp_array = explode(',', $month_temp);
    $tot_temp = 0;
    $temp_array_length = count($temp_array);
    foreach($temp_array as $temp)
    {
        $tot_temp += $temp;
    }
    $avg_high_temp = $tot_temp/$temp_array_length;
    echo "Average Temperature is : ".$avg_high_temp."
    "; 
    sort($temp_array);
    echo " List of five lowest temperatures :";
    for ($i=0; $i< 5; $i++)
    { 
        echo $temp_array[$i].", ";
    }
    echo "List of five highest temperatures :";
    for ($i=($temp_array_length-5); $i< ($temp_array_length); $i++)
    {
        echo $temp_array[$i].", ";
    }
?>

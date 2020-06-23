<?php
    function check_palindrome($string) 
    {
    if ($string == strrev($string))
        return 1;
    else
        return 0;
    }

    $str = "maam";

    if(check_palindrome($str))
        echo 'It is a palindrome ';
    else
        echo "Not a palindrome ";
?>

<?php
    $states = "Mississippi Alabama Texas Massachusetts Kansas";
    $statesArray = [];
    $states1 = explode(' ',$states);

    foreach($states1 as $state) {
        if(preg_match( '/xas$/', ($state)))
            $statesArray[0] = ($state);
    }
    foreach($states1 as $state) {
        if(preg_match('/^k.*s$/i', ($state)))
            $statesArray[1] = ($state);
    }
    foreach($states1 as $state) {
        if(preg_match('/^M.*s$/', ($state)))
            $statesArray[2] = ($state);
    }
    foreach($states1 as $state) {
        if(preg_match('/a$/', ($state)))
            $statesArray[3] = ($state);
    }
    foreach($states1 as $state) {
        if(preg_match('/^M/', ($state)))
            $statesArray[4] = ($state);
    }
    foreach ( $statesArray as $element => $value ){
        print( $value." is the element ". $element."<br/>");
    }
?>
<?php
    $subjects = [
        ["math" , "english" , "arabic"],
        ["French" , "english" , "arabic"],
        ["math" , "english" , "arabic" ,"French"],
        [ "Italy" , "arabic"],

    ];

    echo $subjects [0][0];
    echo $subjects [1][2];
    echo count($subjects); //4
    echo "<hr>";
    foreach ($subjects as $values )
    {
        foreach ($values as $value)
        {
            echo $value ,"<br>";
        }
        echo "<hr>";
    }

    echo "<hr>";

    $numbers = [
        [10,20,50],
        [10,20,50, 50,60],
        [10,2,50,60],
    ];
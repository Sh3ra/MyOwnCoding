<?php

    $students = array(
        "ahmed" => 90,
        "sara" => 100,
        "dina" => 80,
        "mona" => 95,
        "ali" => 88,
        "ahmed" => 100,

    );
   //echo $students["ahmed"];

    foreach ($students as $name => $degree)
    {
        echo $name ."- ". $degree , "<br>";
    }


    echo "<hr>";

    $students_colors = [
        "ahmed" =>"red",
        "ali" => "yellow",
        "sara" => "rgb(150,150,20)",
        "mona" => "pink",
        "dina" => "#ff1570",
        "ghada" => "blue",
        "morad" => "green",
    ];

    foreach ($students_colors as $key => $value)
    {
        echo "<h2 style='color: $value'>$key</h2>";
    }


















<?php
$x =10;

//var_dump($GLOBALS);

function test()
{
    //global $x;
   // echo $x;
    echo $GLOBALS["x"] ,"<br>";
}

test();


$arr =[10=>"sara" , "ahmed" =>10];

echo $arr[10] ,"<hr>";
echo $arr["ahmed"];
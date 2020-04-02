<?php
$names = array("ahmed" , "sara" , "dina" , "mona", "ali" , "mohamed", "gamal");

echo count($names) ,"<br>";
for ($i=0 ; $i<count($names) ;$i++)
    echo $names[$i] , "<br>";


$degrees = [50,60,80,70,90,45,68];
$sum = 0 ;
for($i = 0; $i<count($degrees) ;$i++)
    $sum+= $degrees[$i];
echo $sum;


echo "<hr>";

foreach ($names as $name)
{
    echo $name ,"<br>";
}





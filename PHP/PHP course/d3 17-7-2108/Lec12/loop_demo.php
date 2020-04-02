<?php

for($i = 10; $i<1000 ; $i+=10 )
{
    if ($i == 50) break;
    echo $i , "<br>";

}

echo "<hr>";

for($i = 10; $i<1000 ; $i+=10 )
{
    if ($i == 50) continue;
    echo $i , "<br>";
}
echo "<hr>";
for ($i = 1 ; $i< 3 ;$i++)
{
    for ($j= 1; $j<4;$j++)
    {
        if ($j == $i) continue;
        echo $i , " - " , $j ,"<br>";
    }
}

/*
 *  1 - 2
 *  1 - 3
 *  2 - 1
 *  2 - 3
 */

echo "<hr>";
for ($i = 1 ; $i< 3 ;$i++)
{
    for ($j= 1; $j<4;$j++)
    {
        if ($j == $i)
            break;
        echo $i , " - " , $j ,"<br>";
    }
}
/*
 *  2  - 1
 */
// &nbsp;








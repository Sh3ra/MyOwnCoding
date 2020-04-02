<?php


function print_star($x = 10 , $switch = true)
{
    if ($switch)
    {
        for ($j = $x ; $j >=1 ; $j--)
        {
            for ($i= 1 ; $i<=$j ; $i++)
            {
                echo "* ";
            }
            echo "<br>";
        }
    }else
    {
        for ($j = 1 ; $j <=$x ; $j++)
        {
            for ($i= 1 ; $i<=$j ; $i++)
            {
                echo "* ";
            }
            echo "<br>";
        }
    }

}


print_star();
print_star(5 );
print_star(50 , false);


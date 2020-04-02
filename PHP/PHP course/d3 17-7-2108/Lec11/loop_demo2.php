<?php

	for($i = 1; $i<3;$i++)
	{
		for($j = 2; $j>0 ;$j--) 
			echo "i = $i , j = $j <br/>";
		
		echo "<hr>";
	}	
	/*
		i = 1, j = 2
		i = 1, j = 1
		---------------------
		i = 2, j = 2
		i = 2, j = 1
		---------------------	
	*/
	
	$x = 5;
	$s= 5;
	for ($j=1; $j<=$s ;$j++)
	{
		for ($i=1 ; $i<=$x;$i++)
		{
			echo "* ";
		}
		$x--;
		echo "<br>";
	}
	
	
	echo "<hr>";
	
	$x  = 5;
	$s = 5;
	
	for ($j=1; $j<=$s ;$j++)
	{
		for ($i= $s; $i>=$x;$i--)
		{
			echo "* ";
		}
		$x--;
		echo "<br/>";
	}	
	
	
<?php
	$x = 10;
	$y = 5;
	
	$x = $x + 1; 

	var_dump($x); //11
	
	$x++;
	
	var_dump($x); //12
	
	$y--;
	
	var_dump($y); //4
	
	$z = $x++;
	var_dump($x); //13
	var_dump($z); //12
	
	$z = ++$x + $y--;
	
	var_dump($x); // 14
	var_dump($y); // 3
	var_dump($z); // 18
	
		
	$z = $x-- - --$y;
	
	
	
	var_dump($x); // 13
	var_dump($y); // 2
	var_dump($z); // 12
	
	
	var_dump($y-- ==2); // true
	
	var_dump($y); // 1 
	
	var_dump(++$y ==1); // false
	
	var_dump($y); // 2 
	
	
	////////////////////////////
	//$x = $x +10;
	
	$x +=10;
	
	var_dump($x); // 23
	
	/*
	+=
	-+
	*=
	%=
	
	*/
	
	$x -= $y++;
	var_dump($x); // 21
	var_dump($y); // 3
	
	// z = 12
	
	
	$z += --$x + --$y;
	
	var_dump($x); // 20
	var_dump($y); // 2
	var_dump($z); // 34
	
	
	
	///////////////////////////////
	
	$x ="ahmed";
	var_dump($x);
	
	$x .= " ali";
	
	var_dump($x);
	
	
	
	
	
	
	
	
	
	
	
<?php
	function sayhello($name)
	{
		echo "<hr>";
		echo "<h2>Hello $name</h2>";
		echo "<hr>";
	}

	sayhello("Ahmed");
	sayhello("Sara");
	sayhello("Dina");

	
	function sum($x =10 , $y =20)
	{
		return $x+$y;
	}
		
		
	echo sum(10,50);
	echo "<br>";
	// page scope = global
	$rslt = sum(10,50);
	
	$rslt = sum($rslt , 100) ;	
	echo $rslt; //160
	
	function sum2($x , $y )
	{
		// function scope = local
		global $rslt ;
		$rslt = $x + $y +$rslt;		
	}
	
	echo "<br>";
	sum2(10,50);
	echo $rslt;	
	//echo $z;
	
	function sayHi($name = "ahmed")
	{
		echo "<hr>";
		echo "<h2>Hello $name</h2>";
		echo "<hr>";
	}
	
	sayHi();
	sayHi("sara");
	
	
	
	echo sum();
	echo "<br>";
	echo sum(50);
	echo "<br>";
	echo sum(50,100);
	
	
	
	
	
	
	
	
	
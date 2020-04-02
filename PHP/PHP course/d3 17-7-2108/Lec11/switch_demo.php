<?php

	$grade = "C";

	switch($grade)
	{
		case "A":case "E":
			echo "Excellent";
		break;
		case "B":
			echo "V.Good";
		break;
		case "C":
			echo "Good";
		break;
		case "D":
			echo "Pass"	;
		break;
		default :
			echo "fail";
	}
	echo "<hr>";
	///////////////////////////////////////
	
	 echo 	date("d-n-Y");
	 echo "<hr>";
	 $month=date("n");
	 $day=date("j");
	 
	// $month = 3;
	// $day = 22;
	 switch($month){		 
		case 12: 
			if($day < 23) echo "Autom";
			else echo "winter";
			break;
		case 1 : case 2: 
			echo "winter";
			break;
		case 3: 
			if($day < 21) echo "winter";
			else echo "spring";
			break;
		case 4 : case 5: 
		 echo "spring";
		 break;
		case 6:
			if($day < 21) echo "spring";
			else echo "summer";
			break;
		case 7 : case 8: 
		 echo "summer";
		 break;
		case 9:
			if($day < 21) echo "summer";
			else echo "Autom";
			break;
		case 10 : case 11: 
		 echo "Autom";
			break;
		default :echo "Invalid Month"; 
	 
	 }

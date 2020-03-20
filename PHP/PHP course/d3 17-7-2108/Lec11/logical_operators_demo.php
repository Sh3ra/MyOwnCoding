<?php
	$x = 10;
	$y = 5;
		
	var_dump( ($x >=5) && ($y <=10));  // true
	var_dump( ($x >=5) and ($y <=10));  // true
	var_dump( ($x >=5) && ($y <=10) && ($x >$y));  // true
	var_dump( ($x >=5) && ($y <=10) && ($x <$y));  // false
	
	var_dump( ($x >=5) || ($y <=10) || ($x <$y));  // true
	var_dump( ($x >=5) or ($y <=10) or ($x <$y));  // true
	
	var_dump( ($x >=5) xor ($y <=10) );  // false
	var_dump( !($x >=5) );  // false
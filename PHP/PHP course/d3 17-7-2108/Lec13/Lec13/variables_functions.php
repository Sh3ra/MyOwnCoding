<?php

$x = "ahmed";
//echo $x;
var_dump( isset($x));
var_dump( empty($x));

unset($x);
echo $x;
var_dump( isset($x));
var_dump( empty($x));

$x = false;

var_dump($x);

echo $x;

$x = 0;

if($x) echo "Hello";
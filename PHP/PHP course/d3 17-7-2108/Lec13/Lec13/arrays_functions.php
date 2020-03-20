<?php

$degrees = [50,60,80,70,90,45,68];

echo count($degrees);

sort($degrees );
var_dump($degrees);

rsort($degrees );
var_dump($degrees);

$clients = [
    "sara"=>750,
    "ali"=>250,
    "mohamed"=>150,
    "dina"=>450,
    "farida"=>750,
];

ksort($clients);

var_dump($clients);

asort($clients);
var_dump($clients);



krsort($clients);

var_dump($clients);

arsort($clients);
var_dump($clients);
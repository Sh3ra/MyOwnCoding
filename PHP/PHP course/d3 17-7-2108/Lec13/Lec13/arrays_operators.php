<?php
$x = [50,60,80,70]; // 4

$y = [60,40,90,20,90,45,68]; // 7

$z = $x + $y;

var_dump($z); //11


$clients1 = [
    "sara"=>750,
    "ali"=>250,
];

$clients2 = [
    "mohamed"=>150,
    "ali"=>450,
    "farida"=>750,
];


$clients = $clients1 + $clients2;
var_dump($clients);

$rslt = $z +$clients;
var_dump($rslt);


$x = [50,80,60,70];
$y = [50,60,80,70];

var_dump($x ==$y);

$clients1 = [
    "sara"=>750,
    "ali"=>250,
];


$clients2 = [
    "sara"=>750,
    "ali"=>"250",
];

var_dump($clients1 !==$clients2);
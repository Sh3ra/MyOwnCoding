<?php
//var_dump($_GET);

if ($_SERVER["REQUEST_METHOD"]=="GET")
{
    echo "From Get:<br>";
    echo "welcome " . $_GET["un"] , "<br>";
    echo "your password is " . $_GET["pw"];
}else{
    echo "From post:<br>";
    echo "welcome " . $_POST["un"] , "<br>";
    echo "your password is " . $_POST["pw"];
}

/*

var_dump($_REQUEST);
var_dump($_GET);
var_dump($_POST);
*/
//echo "welcome " . $_REQUEST["un"] , "<br>";
//echo "your password is " . $_REQUEST["pw"];


//var_dump($_SERVER);
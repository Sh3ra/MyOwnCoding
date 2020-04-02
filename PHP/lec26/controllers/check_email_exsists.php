<?php 
require_once "../models/User.php" ;
if( !( isset($_GET['email']) && $_GET['email'] ) ) die ("ERROR 404") ;   
$user = new User() ; 
$user->setEmail($_GET['email']);
$is_valid_email = $user->is_email();
$responce = [
	"state" => $is_valid_email 
]; 
header('Content-Type: application/json');
echo  json_encode($responce) ;

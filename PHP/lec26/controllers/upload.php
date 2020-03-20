<?php 
require_once "../models/Image.php" ;
require_once "../libs/upload.php" ;
if ( !isset( $_FILES['fileToUpload'] ) ) die ("ERROR 404") ;
$is_image =  upload_image ( 'fileToUpload' ) ;
if( $is_image ) {
	$image = new Image() ; 
	$image->setPath( $is_image ) ;
	$image->save() ;
}
header("location:\lec26\views\galary.php");
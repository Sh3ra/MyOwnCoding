<?php
function upload_image( string $image_name )  {
	$target_dir = "uploads/images/";
	$target_file = $target_dir . basename($_FILES[$image_name]["name"]);
	$uploadOk = true;
	$imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));
	
	if ($_FILES[$image_name]["size"] > 5000000) {
		$uploadOk = false;
	}
	
	if (file_exists($target_file)) {
		$uploadOk = false;
	}
	
	if(
	$imageFileType != "jpg" && 
	$imageFileType != "png" && 
	$imageFileType != "jpeg"&& 
	$imageFileType != "gif" ) {
		$uploadOk = false;
	}
	
    $check = getimagesize($_FILES[$image_name]["tmp_name"]);
    if($check === false) {
        $uploadOk = false ;
    }
	
    if ( $uploadOk && move_uploaded_file($_FILES[$image_name]["tmp_name"], $target_file)) {
        return $target_file;
    } else {
		 $uploadOk =  false ;
	}
	
	return $uploadOk ; 

} 

?>
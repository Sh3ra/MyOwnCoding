<!DOCTYPE html>
<html>
<body>

<form 
	action="/lec26/controllers/upload.php" 
	method="POST" 
	enctype="multipart/form-data"
	>
    Select image to upload:
    <input type="file" name="fileToUpload" id="fileToUpload" >
    <input type="submit" value="Upload Image" name="submit">
</form>

</body>
</html>
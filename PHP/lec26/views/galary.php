<?php 
require_once "../models/Image.php" ;
//$images = (new Image())->all();
$imagesObject = new Image();
$images = $imagesObject->all() ;
?>

<!DOCTYPE html>
<html>
<body>

<?php if ( is_array($images) && count($images) > 0 ) : ?>  
<table border=1 >
	<th>
		<td> 
			ID
		</td>
		<td>
			IMAGE
		</td>
	</th> 
	<?php foreach ($images as $id => $image ) : ?> 
		<tr>
			<td> 
				<?=$id?> 
			</td>
			<td>
				<?=$image->getImage()?>
			</td>
		</tr>
	<?php endforeach; ?>
 </table>
 <?php else: ?> 
 <p> Galary is empty </p> 
 <?php endif;  ?>

</body>
</html>
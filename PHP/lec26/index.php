<!doctype html>

<html>
<head>

  <title>The HTML5 Herald</title>



</head>

<body>
  <div> 
   <h1> 
		Welcome
   </h1>
  </div>
  <div >
  <input type="search" placeholder="enter any email ... " id="search" > <br>
  <div id="res">
  </div> 
  </div>
  <script
  src="https://code.jquery.com/jquery-3.3.1.js"
  integrity="sha256-2Kok7MbOyxpgUVvAk/HJ2jigOSYS2auK4Pfzbm7uH60="
  crossorigin="anonymous"></script>
  <script>
  /*
  function li (data) {
	return `<li> ${data} </li> `;
  }
	$("#search").keyup( function () {
	
		//var self = this ;
		
	});
	*/

	let success_callback = function(respond){
					$("#res").html('');
					console.log(respond)
					if ( respond.state ) {
						$("#res").html('<p style="color:red"> Sorry, This email is already taken </p>');
					} else {
						$("#res").html('<p style="color:green"> this email is valid ! </p>');
					}
				};

	
	let onKeyUpdo = function () {
		let  email = $("#search").val()
			$.ajax({
					url: `http://localhost/lec25/controllers/check_email_exsists.php?email=${email}`, 
					success: success_callback 
			});
	}
	
	$("#search").keyup (onKeyUpdo);









 
  </script>
</body>
</html>
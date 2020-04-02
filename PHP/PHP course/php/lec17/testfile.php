<!DOCTYPE html>
<html> 
<body>
  <h1 id="head">Welcome to our first Application</h1>
  <a href="views/reg1.php">Join now</a>
  <script>
    
  //var x ="ahmed"; // to dentify a variable
  document.getElementById('head').innerHTML = 'Hello JavaScript!'; //document ya3ni el page eli an wa2ef feha
  function Myfont()
  {
    document.getElementById('head').style.fontSize='50px';
  }
  //document.getElementById('head').style.display='none';// to hidethe elment
  document.getElementById('head').style.display='block';  //to show hiding element
  //head.innerHTML ="welcome home" ;//change content of head 
  //head.style = "color:red";
  //alert("hello");
  //if (x =="ahmed") alert(`hello ${x}`) ;
  </script>
    <script type="text/javascript">
    document.getElementById("pass").addEventlistener("keyup",function() {
      document.getElementById("head").innerHTML =this.value;
    });
  </script>
</body>
</html>
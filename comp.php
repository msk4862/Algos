<html>
<head>
   <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
    <meta name="description" content="">
    <meta name="author" content="">
    <link rel="icon" href="favicon.ico">
    
	<script src="js/jquery.min.js"></script>
<script src="js/bootstrap.min.js"></script>
	<mob>
	   HRC | CS
	</mob>

	<link rel="stylesheet" type="text/css" href="css/bootstrap.css" />
	<link rel="stylesheet" type="text/css" href="css/style.css" />
  <link rel="stylesheet" type="text/css" href="css/style.css" />
  
  <style>
    .people{
      <?php
        include("menuBGColor.php");
        fillBG();
       ?>
    }
    </style>
    
</head>			
<body>
    <?php
      include("header.php");
      require("initiate.php");
      generateHeader();
      $conn=initiateConn("cs","");
if($conn->error)
	{
		echo $conn->error;
		exit("Mysql error");
	}
$result=$conn->query("select roll from students where startyear like '2016'");
    ?>
<br/>
			<br/>
   <center> <div id="container">
			<h2>Competition</h2>
		<!--<form id="competition" method="POST" action="compsave.php">	
		Roll No:	
			      <?php 
echo"
 <select name='roll'>";
    while($row=$result->fetch_assoc()){
    $value=$row['roll'];
    echo"<option value=$value>$value</option>";
}
echo " </select>";?>
			<br/>
<br/>			
		Name:	<input id="title" name="title" maxlength="50" type="text" style="width:20%" placeholder="Name" required></input>
			
			<br/>
			<br/>
		
			
		Email  :	<input id="email" name="email" maxlength="50" type="email" style="width:20%" placeholder="email@domain.con" required></input>
			
			<br/>
			<br/>
		Mob &nbsp:	<input id="mob" name="mob" maxlength="11" type="number" style="width:20%" placeholder="contact" required></input>
			
			<br/>
			<br/>
			<button type="submit" name="competition"  value="submit" >submit</button>
			</form>
		
		</div>-->
		<br/><b>Registrations Are Closed!!!!!!</b><br/>
			Contact the Organiser for further Help!!!
		</center>
		
</body>
        
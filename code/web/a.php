<!doctype HTML>
<html>
<head></head>
<body>
hello
<?php
echo $_POST["name"];
$con = mysql_connect('localhost','root','arbit123');
if (!$con){
  die('Could not connect: ' . mysql_error());
}
echo $_POST["pass"];
if(!mysql_select_db("users", $con))
	die("not");

$sql="Insert into account(username,password) Values('".$_POST["name"]."','".$_POST["pass"]."')";
echo $sql;
if(!mysql_query($sql,$con))
	die("invalid");
else
	echo "one added";
mysql_close($con);
?>
</body>
</html>

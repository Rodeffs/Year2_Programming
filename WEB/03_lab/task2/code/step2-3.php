<?php

if (isset($_POST["name"], $_POST["surname"], $_POST["age"], $_POST["salary"], $_POST["email"]))  {

	session_start();

	$_SESSION["name"] = $_POST["name"];
	$_SESSION["surname"] = $_POST["surname"];
	$_SESSION["age"] = $_POST["age"];
	$_SESSION["salary"] = $_POST["salary"];
	$_SESSION["email"] = $_POST["email"];
	$_SESSION["data"] = [$_POST["name"], $_POST["surname"], $_POST["age"], $_POST["salary"], $_POST["email"]];

	echo "<h1>The output for step 2:</h1>";

	// nl2br превращает \n в <br>
	echo nl2br("Your name is {$_SESSION["name"]}\n");	
	echo nl2br("Your surname is {$_SESSION["surname"]}\n");	
	echo nl2br("Your age is {$_SESSION["age"]}\n");	
	echo nl2br("Your salary is {$_SESSION["salary"]}\n");	
	echo nl2br("Your email is {$_SESSION["email"]}\n");
	
	echo "<h1>The output for step 3:</h1>";
	
	echo "<ul>";
	foreach ($_SESSION["data"] as $i) {
		echo "<li>{$i}</li>";
	}
	echo "</ul>";
}

?>


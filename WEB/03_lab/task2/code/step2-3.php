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

	echo "Your name is {$_SESSION["name"]}<br>";	
	echo "Your surname is {$_SESSION["surname"]}<br>";	
	echo "Your age is {$_SESSION["age"]}<br>";	
	echo "Your salary is {$_SESSION["salary"]}<br>";	
	echo "Your email is {$_SESSION["email"]}<br>";
	
	echo "<h1>The output for step 3:</h1>";
	
	echo "<ul>";
	foreach ($_SESSION["data"] as $i) {
		echo "<li>{$i}</li>";
	}
	echo "</ul>";
}

?>


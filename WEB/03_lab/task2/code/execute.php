<?php
if (isset($_POST["name"], $_POST["surname"], $_POST["age"], $_POST["salary"], $_POST["email"]))  {

	session_start();

	$name = $_POST["name"];
	$surname = $_POST["surname"];
	$age = $_POST["age"];
	$salary = $_POST["salary"];
	$email = $_POST["email"];

	$_SESSION["name"] = $name;
	$_SESSION["surname"] = $surname;
	$_SESSION["age"] = $age;
	$_SESSION["salary"] = $salary;
	$_SESSION["email"] = $email;

	header("Location /step2-3.php");
	exit();
}
?>


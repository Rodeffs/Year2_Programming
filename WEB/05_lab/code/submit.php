<?php

function goBack() {
	header("Location: /");
	exit();
}

if (false === isset($_POST["email"], $_POST["category"], $_POST["title"], $_POST["content"]))  {
	goBack();
}

$email = $_POST["email"];
$category = $_POST["category"];
$title = $_POST["title"];
$content = $_POST["content"];

$mysqli = new mysqli("localhost", "root", "password", "web");

if ($mysqli->connect_errno) {
	printf("Connect failed: %s\n", $mysqli->connect_error);
	exit;
}

$mysqli->query('INSERT INTO ad (category, email, title, content) VALUES($category, $email, $title, $content)');

goBack();

?>

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

$filePath = "categories/{$category}/{$title}.txt";

if (false === file_put_contents($filePath, $content)) {
	throw new Exception("Error while writing content to a file");
}

// File permissions in Linux:
// 	First digit - owner
// 	Second digit - group
// 	Third digit - others
// To come up with a digit for each category you need to sum up the following numbers:
// 	4 - for read access
// 	2 - for write access
// 	1 - for execute access
// E.g. if I need a file that the owner can read, write and execute, the group can only read and execute and all others can't do anything, then I write:
// 	chmod 750 file

chmod($filePath, 0777);

goBack();

?>

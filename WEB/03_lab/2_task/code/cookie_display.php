<?php

function goBack() {
	header("Location: /");
	exit();
}

if (false === isset($_POST['text1'])){
	goBack();
}

$text = $_POST['text1'];
$word_count = str_word_count($text);
$char_count = strlen($text);

setcookie("word_count", $word_count, time() + 30);
setcookie("char_count", $char_count, time() + 30);

goBack();

?>

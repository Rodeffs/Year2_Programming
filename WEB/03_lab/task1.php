<?php

echo "Шаг 1\n\n";

// Я так понимаю в задании имелось ввиду любые два символа между буквами a, иначе строки abba и прочие найти по данному шаблону нельзя

$str = "ahb acb aeb aeeb adcb axeb abba adea adca abea";

$regexp = '/a..a/';
// Если имеется ввиду ТОЛЬКО строки abba, adca и abea, то тогда
// $regexp = '/a[b|d][c|e]a/';

$matches = [];

$count = preg_match_all($regexp, $str, $matches);

echo "Найдено строк по шаблону: {$count}\n\n";

var_dump($matches);



echo "\n\nШаг 2\n\n";

$expr = 'a1b2c3';

echo "было: {$expr}\n";

// Я так понимаю, под целыми числами подрузумеваются 1, 2 и 3, а не a1, b2 и c3 как произвольные переменные

$regexp2 = '/[0-9]+/';
// Если имеется ввиду ТОЛЬКО числа 1, 2 и 3, то
// $regexp2 = '/[1-3]/';

$integers = [];

preg_match_all($regexp2, $expr, $integers);

$replacements = [];

foreach ($integers[0] as $i) {
	$res = pow($i, 3);
	array_push($replacements, (string) $res);
}

for ($i = 0; $i < sizeof($replacements); $i++) {
	$old_var = "/{$integers[0][$i]}/";
	$expr = preg_replace($old_var, $replacements[$i], $expr);
}

echo "стало: {$expr}\n";

?>
